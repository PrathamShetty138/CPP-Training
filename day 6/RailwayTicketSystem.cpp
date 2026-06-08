#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

enum class BerthClass  { SLEEPER, AC_3, AC_2, GENERAL };
enum class TicketStatus { CONFIRMED, RAC, WAITLIST, CANCELLED };

string berthToStr(BerthClass b) {
    switch(b) {
        case BerthClass::SLEEPER: return "Sleeper";
        case BerthClass::AC_3:    return "AC 3-Tier";
        case BerthClass::AC_2:    return "AC 2-Tier";
        case BerthClass::GENERAL: return "General";
    }
    return "Unknown";
}

string statusToStr(TicketStatus s) {
    switch(s) {
        case TicketStatus::CONFIRMED: return "CONFIRMED";
        case TicketStatus::RAC:       return "RAC";
        case TicketStatus::WAITLIST:  return "WAITLIST";
        case TicketStatus::CANCELLED: return "CANCELLED";
    }
    return "Unknown";
}

class Passenger {
private:
    int         ticketID;
    string      name;
    int         age;
    BerthClass  berthClass;
    TicketStatus status;
    string      from;
    string      to;
    string      date;

public:
    Passenger() : ticketID(0), age(0),
                  berthClass(BerthClass::GENERAL),
                  status(TicketStatus::WAITLIST) {}

    Passenger(int id, string n, int a, BerthClass bc,
              TicketStatus st, string f, string t, string d)
        : ticketID(id), name(n), age(a), berthClass(bc),
          status(st), from(f), to(t), date(d) {}

   
    int          getTicketID()  const { return ticketID;  }
    string       getName()      const { return name;      }
    TicketStatus getStatus()    const { return status;    }
    BerthClass   getBerthClass()const { return berthClass;}

  
    void setStatus(TicketStatus s) { status = s; }

    void display() const {
        cout << "  Ticket ID   : " << ticketID              << "\n"
             << "  Passenger   : " << name                  << "  (Age: " << age << ")\n"
             << "  From --> To : " << from << " --> " << to << "\n"
             << "  Date        : " << date                  << "\n"
             << "  Class       : " << berthToStr(berthClass)<< "\n"
             << "  Status      : " << statusToStr(status)   << "\n";
    }
};


class User {
private:
    string username;
    string password;

public:
    User() {}
    User(string u, string p) : username(u), password(p) {}

    string getUsername()                    const { return username; }
    bool   checkPassword(const string& p)   const { return password == p; }
};


class Train {
private:
    static const int MAX_CONFIRMED = 5;
    static const int MAX_RAC       = 1;
    static const int MAX_WL        = 2;

    int nextID;

    vector<Passenger> confirmedList;   
    queue<Passenger>  racQueue;        
    queue<Passenger>  wlQueue;        

   
    vector<Passenger*> allPassengers; 

    

public:
    Train() : nextID(1001) {}

    
    bool bookTicket(const string& name, int age, BerthClass bc,
                    const string& from, const string& to, const string& date) {

        TicketStatus status;

        if ((int)confirmedList.size() < MAX_CONFIRMED) {
            status = TicketStatus::CONFIRMED;
        } else if ((int)racQueue.size() < MAX_RAC) {
            status = TicketStatus::RAC;
        } else if ((int)wlQueue.size() < MAX_WL) {
            status = TicketStatus::WAITLIST;
        } else {
            cout << "\n  [!] No seats available. Train is fully booked (WL full).\n";
            return false;
        }

        Passenger p(nextID++, name, age, bc, status, from, to, date);

        if      (status == TicketStatus::CONFIRMED) confirmedList.push_back(p);
        else if (status == TicketStatus::RAC)        racQueue.push(p);
        else                                         wlQueue.push(p);

        cout << "\n  [OK] Ticket booked! ID: " << (nextID - 1)
             << "  Status: " << statusToStr(status) << "\n";
        return true;
    }

   
    bool cancelTicket(int ticketID) {
        // 1. Search confirmed list
        for (int i = 0; i < (int)confirmedList.size(); i++) {
            if (confirmedList[i].getTicketID() == ticketID) {
                confirmedList[i].setStatus(TicketStatus::CANCELLED);
                cout << "\n  [OK] Ticket " << ticketID << " (CONFIRMED) cancelled.\n";
                confirmedList.erase(confirmedList.begin() + i);

                // Promote RAC -> Confirmed
                if (!racQueue.empty()) {
                    Passenger promoted = racQueue.front(); racQueue.pop();
                    promoted.setStatus(TicketStatus::CONFIRMED);
                    confirmedList.push_back(promoted);
                    cout << "  [>>] Passenger '" << promoted.getName()
                         << "' promoted: RAC --> CONFIRMED\n";

                    // Promote WL -> RAC
                    if (!wlQueue.empty()) {
                        Passenger wlp = wlQueue.front(); wlQueue.pop();
                        wlp.setStatus(TicketStatus::RAC);
                        racQueue.push(wlp);
                        cout << "  [>>] Passenger '" << wlp.getName()
                             << "' promoted: WL --> RAC\n";
                    }
                }
                return true;
            }
        }

        // 2. Search RAC queue
        {
            queue<Passenger> temp;
            bool found = false;
            while (!racQueue.empty()) {
                Passenger p = racQueue.front(); racQueue.pop();
                if (p.getTicketID() == ticketID && !found) {
                    found = true;
                    cout << "\n  [OK] Ticket " << ticketID << " (RAC) cancelled.\n";
                    // Promote WL -> RAC
                    if (!wlQueue.empty()) {
                        Passenger wlp = wlQueue.front(); wlQueue.pop();
                        wlp.setStatus(TicketStatus::RAC);
                        temp.push(wlp);
                        cout << "  [>>] Passenger '" << wlp.getName()
                             << "' promoted: WL --> RAC\n";
                    }
                } else {
                    temp.push(p);
                }
            }
            racQueue = temp;
            if (found) return true;
        }

        // 3. Search WL queue
        {
            queue<Passenger> temp;
            bool found = false;
            while (!wlQueue.empty()) {
                Passenger p = wlQueue.front(); wlQueue.pop();
                if (p.getTicketID() == ticketID && !found) {
                    found = true;
                    cout << "\n  [OK] Ticket " << ticketID << " (WAITLIST) cancelled.\n";
                } else {
                    temp.push(p);
                }
            }
            wlQueue = temp;
            if (found) return true;
        }

        cout << "\n  [!] Ticket ID " << ticketID << " not found.\n";
        return false;
    }

    void viewAllSeats() const {
        cout << "\n  ---- CONFIRMED SEATS (" << confirmedList.size() << "/" << MAX_CONFIRMED << ") ----\n";
        if (confirmedList.empty()) cout << "  (none)\n";
        for (auto& p : confirmedList) {
            cout << "  -----------------------------------\n";
            p.display();
        }

        cout << "\n  ---- RAC (" << racQueue.size() << "/" << MAX_RAC << ") ----\n";
        {
            queue<Passenger> tmp = racQueue;
            if (tmp.empty()) cout << "  (none)\n";
            while (!tmp.empty()) {
                cout << "  -----------------------------------\n";
                tmp.front().display(); tmp.pop();
            }
        }

        cout << "\n  ---- WAITING LIST (" << wlQueue.size() << "/" << MAX_WL << ") ----\n";
        {
            queue<Passenger> tmp = wlQueue;
            if (tmp.empty()) cout << "  (none)\n";
            while (!tmp.empty()) {
                cout << "  -----------------------------------\n";
                tmp.front().display(); tmp.pop();
            }
        }
        cout << "  -----------------------------------\n";
    }

    void showAvailability() const {
        cout << "  Confirmed : " << (MAX_CONFIRMED - (int)confirmedList.size())
             << " seats free  |  RAC : " << (MAX_RAC - (int)racQueue.size())
             << " free  |  WL : " << (MAX_WL - (int)wlQueue.size()) << " free\n";
    }
};


class RailwaySystem {
private:
    vector<User> users;        
    Train        train;         
    User*        loggedInUser;

   
    BerthClass selectBerthClass() {
        int ch;
        cout << "  Select Class:\n"
             << "  1. Sleeper\n"
             << "  2. AC 3-Tier\n"
             << "  3. AC 2-Tier\n"
             << "  4. General\n"
             << "  Choice : ";
        cin >> ch;
        switch(ch) {
            case 1: return BerthClass::SLEEPER;
            case 2: return BerthClass::AC_3;
            case 3: return BerthClass::AC_2;
            default: return BerthClass::GENERAL;
        }
    }

public:
    RailwaySystem() : loggedInUser(nullptr) {}

   
    void registerUser() {
        string uname, pwd, confirm;
        cout << "\n  ---- REGISTER ----\n";
        cout << "  Username        : "; cin >> uname;

        for (auto& u : users) {
            if (u.getUsername() == uname) {
                cout << "  [!] Username already exists.\n"; return;
            }
        }
        cout << "  Password        : "; cin >> pwd;
        cout << "  Confirm password: "; cin >> confirm;

        if (pwd != confirm) { cout << "  [!] Passwords do not match.\n"; return; }

        users.push_back(User(uname, pwd));
        cout << "  [OK] Registered successfully!\n";
    }

    bool loginUser() {
        if (loggedInUser) {
            cout << "  [!] Already logged in as " << loggedInUser->getUsername() << "\n";
            return true;
        }
        string uname, pwd;
        cout << "\n  ---- LOGIN ----\n";
        cout << "  Username : "; cin >> uname;
        cout << "  Password : "; cin >> pwd;

        for (auto& u : users) {
            if (u.getUsername() == uname && u.checkPassword(pwd)) {
                loggedInUser = &u;
                cout << "  Welcome, " << uname << "!\n";
                return true;
            }
        }
        cout << "  [!] Invalid credentials.\n";
        return false;
    }

   
    void logoutUser() {
        if (!loggedInUser) { cout << "  [!] No user logged in.\n"; return; }
        cout << "  Goodbye, " << loggedInUser->getUsername() << "!\n";
        loggedInUser = nullptr;
    }

    void bookTicket() {
        if (!loggedInUser) { cout << "  [!] Please login first.\n"; return; }

        cout << "\n  ---- BOOK TICKET ----\n";
        train.showAvailability();

        string name, from, to, date;
        int age;

        cout << "  Passenger Name  : "; cin >> name;
        cout << "  Age             : "; cin >> age;
        BerthClass bc = selectBerthClass();
        cout << "  From (city)     : "; cin >> from;
        cout << "  To   (city)     : "; cin >> to;
        cout << "  Date (DD/MM/YY) : "; cin >> date;

        train.bookTicket(name, age, bc, from, to, date);
    }

    
    void cancelTicket() {
        if (!loggedInUser) { cout << "  [!] Please login first.\n"; return; }
        train.viewAllSeats();
        int id;
        cout << "  Enter Ticket ID to cancel : "; cin >> id;
        train.cancelTicket(id);
    }


    void viewSeats() {
        if (!loggedInUser) { cout << "  [!] Please login first.\n"; return; }
        train.viewAllSeats();
    }

    void run() {
        int choice;
        cout << "\n";
        cout << "  --------------------------------\n";
        cout << "  |  TRAIN TICKET BOOKING SYSTEM |\n";
        cout << "  --------------------------------\n";

        do {
            cout << "\n  ---- MAIN MENU -------------------\n";
            if (loggedInUser)
                cout << "  Logged in as : " << loggedInUser->getUsername() << "\n";
            cout << "  1. Register\n"
                 << "  2. Login\n"
                 << "  3. Book Ticket\n"
                 << "  4. Cancel Ticket\n"
                 << "  5. View All Seats\n"
                 << "  6. Logout\n"
                 << "  0. Exit\n"
                 << "  ----------------------------------\n"
                 << "  Choice : ";
            cin >> choice;

            switch (choice) {
                case 1: registerUser(); break;
                case 2: loginUser();    break;
                case 3: bookTicket();   break;
                case 4: cancelTicket(); break;
                case 5: viewSeats();    break;
                case 6: logoutUser();   break;
                case 0: cout << "  Exiting... Goodbye!\n"; break;
                default: cout << "  [!] Invalid option.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    RailwaySystem system;
    system.run();
    return 0;
}
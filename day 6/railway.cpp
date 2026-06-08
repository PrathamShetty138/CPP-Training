#include <iostream>
#include <vector>
using namespace std;

class User {
public:
    string username;
    string password;

    User(string u, string p) {
        username = u;
        password = p;
    } 
};

class Passenger {
public:
    int id;
    string name;
    string status;

    Passenger(int i, string n, string s) {
        id = i;
        name = n;
        status = s;
    }
};

class RailwaySystem {

private:

    vector<User> users;
    vector<Passenger> passengers;

    bool loggedIn = false;

    int confirmed = 0;
    int rac = 0;
    int waiting = 0;

    int ticketID = 1001;

public:

    void registerUser() {

        string uname, pass;
        cout << "\n--- REGISTER ---\n";
        cout << "Enter Username : ";
        cin >> uname;
        cout << "Enter Password : ";
        cin >> pass;
        users.push_back(User(uname, pass));
        cout << "Registration Successful!\n";
    }

    void loginUser() {
        string uname, pass;
        cout << "\n--- LOGIN ---\n";
        cout << "Enter Username : ";
        cin >> uname;
        cout << "Enter Password : ";
        cin >> pass;
        for (int i = 0; i < users.size(); i++) {

            if (users[i].username == uname &&
                users[i].password == pass) {
                loggedIn = true;
                cout << "\nLogin Successful!\n";
                return;
            }
        }
        cout << "\nInvalid Username or Password!\n";
    }

    void bookTicket() {
        if (!loggedIn) {
            cout << "\nPlease Login First!\n";
            return;
        }
        if (passengers.size() == 5) {
            cout << "\nTrain Full!\n";
            return;
        }
        string name;
        cout << "\nEnter Passenger Name : ";
        cin >> name;
        string status;
        if (confirmed < 2) {
            status = "CONFIRMED";
            confirmed++;
        }
        else if (rac < 1) {
            status = "RAC"; 
            rac++;
        }
        else {
            status = "WAITING";
            waiting++;
        }
        Passenger p(ticketID, name, status);
        passengers.push_back(p);
        cout << "\nTicket Booked Successfully!\n";
        cout << "Ticket ID : " << ticketID << endl;
        cout << "Status    : " << status << endl;
        ticketID++;
    }
    void cancelTicket() {

        if (!loggedIn) {
            cout << "\nPlease Login First!\n";
            return;
        }

        int id;

        cout << "\nEnter Ticket ID to Cancel : ";
        cin >> id;

        for (int i = 0; i < passengers.size(); i++) {

            if (passengers[i].id == id) {

                string cancelledStatus = passengers[i].status;

                passengers.erase(passengers.begin() + i);

                cout << "\nTicket Cancelled Successfully!\n";

                if (cancelledStatus == "CONFIRMED") {

                    for (int j = 0; j < passengers.size(); j++) {

                        if (passengers[j].status == "RAC") {

                            passengers[j].status = "CONFIRMED";

                            rac--;
                            confirmed++;

                    
                            for (int k = 0; k < passengers.size(); k++) {

                                if (passengers[k].status == "WAITING") {

                                    passengers[k].status = "RAC";

                                    waiting--;
                                    rac++;

                                    break;
                                }
                            }

                            break;
                        }
                    }
                }

                return;
            }
        }

        cout << "\nTicket Not Found!\n";
    }
    void viewTickets() {

        if (!loggedIn) {
            cout << "\nPlease Login First!\n";
            return;
        }

        if (passengers.empty()) {
            cout << "\nNo Tickets Booked!\n";
            return;
        }

        cout << "\n------ TICKETS ------\n";

        for (int i = 0; i < passengers.size(); i++) {

            cout << "\nTicket ID : " << passengers[i].id << endl;
            cout << "Name      : " << passengers[i].name << endl;
            cout << "Status    : " << passengers[i].status << endl;
        }
    }
    void run() {

        int choice;

        do {

            cout << "\n===== RAILWAY RESERVATION SYSTEM =====\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Book Ticket\n";
            cout << "4. Cancel Ticket\n";
            cout << "5. View Tickets\n";
            cout << "6. Exit\n";
            cout << "Enter Choice : ";
            cin >> choice;

            switch(choice) {

                case 1:
                    registerUser();
                    break;

                case 2:
                    loginUser();
                    break;

                case 3:
                    bookTicket();
                    break;

                case 4:
                    cancelTicket();
                    break;

                case 5:
                    viewTickets();
                    break;

                case 6:
                    cout << "\nThank You!\n";
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
            }

        } while(choice != 6);
    }
};

int main() {

    RailwaySystem r;
    r.run();
    return 0;
}
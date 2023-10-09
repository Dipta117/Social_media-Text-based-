/*
Concepts covered in my project :

1.Constructor
2.Destructor
3.Friend class
4.Friend function
5.Pure virtual function
6.Abstruct Class
7.virtual class
8.Inheritance
9.File management
10.STL (Vector , Map ,List )
11.Class Templete

*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

template <typename T>
class VectorWithDefaultValues;

// Function template to find the maximum value in a VectorWithDefaultValues
template <typename T>
T findMax(VectorWithDefaultValues<T>& v) {
    T maxVal = v.get(0);
    for (int i = 1; i < v.size(); ++i) {
        T val = v.get(i);
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}

template <typename T1, typename T2>
class MapWithDefaultValues {
public:
    MapWithDefaultValues(T2 defaultValue) : defaultValue(defaultValue) {}

    void insert(T1 key, T2 value) {
        map[key] = value;
    }

    T2 get(T1 key) {
        if (map.find(key) != map.end()) {
            return map[key];
        }
        return defaultValue;
    }

private:
    map<T1, T2> map;
    T2 defaultValue;
};
//class templete
template <typename T>
class VectorWithDefaultValues {
public:
    VectorWithDefaultValues(T defaultValue) : defaultValue(defaultValue) {}

    void push_back(T value) {
        vector.push_back(value);
    }

    T get(int index) {
        if (index >= 0 && index < vector.size()) {
            return vector[index];
        }
        return defaultValue;
    }


    int size() const {
        return vector.size();
    }


private:
    vector<T> vector;
    T defaultValue;
};

class main_profile {
public:
    //pure virtual functions
    virtual void bio() = 0;
    virtual void uni() = 0;
    virtual void work() = 0;
    virtual void cucity() = 0;
    virtual void homett() = 0;
};

class start {
protected:
    string fname, lname, dob, phone, email, password, p, fullname, filename;
    int i, key;

    MapWithDefaultValues<string, string> emailPhoneMap{ "" };         //
    MapWithDefaultValues<string, string> emailPasswordMap{ "" };
    VectorWithDefaultValues<string> friendsVector{ "" };
   queue<string> friendRequestsQueue;
    list<string> postsList;


    friend class write;
    friend class setting;
    friend class Profile;
    friend class friends;
    friend class friendlist;

public:
    start() {
       //default constructor
    }
//parameterized constructor
    start(const string& first_name, const string& last_name, const string& email, const string& password) {
        fname = first_name;
        lname = last_name;
        this->email = email;
        this->password = password;
        p = password;
        fullname = fname + " " + lname;
        friendsVector.push_back(fullname);
        filename = email + "_" + password + ".txt";
    }

    void getdata() {
        vector<string>email_id;
vector<string>phone_no;
vector<string>pass;


        cout << "                                     First Name : ";
        cin >> fname;
        cout << "                                     Last Name :";
        cin >> lname;
        cout << "                                     Phone Number : ";
        cin >> phone;
        emailPhoneMap.insert(email, phone);
 phone_no.push_back(phone);
        cout << "                                     Email : ";
        cin >> email;
        emailPasswordMap.insert(email, password);
email_id.push_back(email);
        cout << "                                     Password : ";
        cin >> password;
        pass.push_back(password);
        cout << "                                     Re-type password :";
        cin >> p;
        if (p != password) {
            cout << "                                     Account Creation Failed  !!!! " << endl<<"Password not matched"<<endl;
            exit(0);
        }
          pass.push_back(password);
        fullname = fname + " " + lname;


    ofstream out;
out.open("login_info.txt",ios::app);

    for(int i=0;i<email_id.size();i++)

    {
        out<<email_id[i]<<"  "<<phone_no[i]<<"   "<<pass[i]<<"  "<<endl;
    }
        friendsVector.push_back(fullname);
  string      filename = email + "_" + password + ".txt";

ofstream io;
io.open(filename.c_str(),ios::out);
 io<<fname<<"_"<<lname;
ofstream ff;
    ff.open("friends.txt",ios::app);
        cout<<"The Facebook account named "<<fullname<<" has been created successfully"<<endl;
        ff<<fname<<"_"<<lname<<endl;

        out.close();
        io.close();
    }


//friend function declaration
    friend void log_in(start g);
};
//friend function definition
void log_in(start g) {
    ifstream in;
    in.open("login_info.txt", ios::in);
    string em, pas, ph;
    bool found = false;

    cout << "                                     Email Address : ";
    cin >> em;

    cout << "                                     Phone No :";
    cin >> ph;
    cout << "                                     Password :";
    cin >> pas;
    string hg;
    string findd = em + "_" + pas + ".txt";
    ifstream f(findd.c_str());

    if (f.good())
        cout <<endl<< "                                     Log in successful" << endl;

        else
            cout<<endl<<"                                     Log in unsuccessful. Invalid info  given"<<endl;

    while (!f.eof()) {
        getline(f, hg);
    }
    f.close();
}
//setting inherits start class and main_profile class
class setting : virtual public start, public main_profile {
protected:
    string ins, wp, txt, bi, homet, cc;
    friend class Profile;

public:
    void tx(start d) {
        txt = d.fname + "_" + d.lname + ".txt";
    }
    void nam(start d) {
        ofstream o;
        o.open(txt.c_str(), ios::app);
        o << "====================================" << endl;
        o << d.fullname << endl;
        o << "====================================" << endl << endl;
        o << "Email :" << d.email << endl;
        o << "Contact no :" << d.phone << endl;
    }
    void show()
    {

        ifstream in;
        in.open(txt.c_str(), ios::in);



        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }

        in.close();
    }

    void bio() override {
        ofstream o;
        o.open(txt.c_str(), ios::app);

        cout << "Add Bio : ";
        cin.ignore();
        getline(cin, bi);
        o << "About me : " << bi << endl;
    }

    void uni() override {
        ofstream o;
        o.open(txt.c_str(), ios::app);

        cout << "Add University/College :";
        cin.ignore();
        getline(cin, ins);
        o << "University/College : " << ins << endl;
    }
    void work() override {
        ofstream o;
        o.open(txt.c_str(), ios::app);

        cout << "Add workplace : ";
        cin.ignore();
        getline(cin, wp);
        o << "Workplace : " << wp << endl;
    }

    void cucity() override {
        ofstream o;
        o.open(txt.c_str(), ios::app);

        cout << "Add Current city : ";
        cin.ignore();
        getline(cin, cc);
        o << "Current City : " << cc << endl;
    }
    void homett() override {
        ofstream o;
        o.open(txt.c_str(), ios::app);

        cout << "Add Hometown : ";
        cin.ignore();
        getline(cin, homet);
        o << "Hometown : " << homet << endl;
    }
};

class delete_ac {
protected:
    string fnam, lnam, email_del, pass_del, txt;

public:
    delete_ac() {
        // Default constructor
    }
    //parameterized constructor
    delete_ac(const string& fn, const string& ln, const string& e, const string& ps) {
        fnam = fn;
        lnam = ln;
        email_del = e;
        pass_del = ps;
        txt = fnam + "_" + lnam + ".txt";
    }
//destructor to delete account
    ~delete_ac() {
        if (remove(txt.c_str()) == 0) {
            cout << "Account file " << txt << " deleted successfully." << endl;
        }
    }
};

class write {
protected:
    string write_post;
    friend class Profile;

public:
    void post(start s) {
        char ch;

        time_t currentTime = time(0);

        tm* timeInfo = localtime(&currentTime);

        char timeBuffer[80];

        string fil = s.fname + "_" + s.lname + ".txt";
        ofstream io, io1;
        io1.open("post.txt", ios::app);
        io.open(fil.c_str(), ios::app);
        io << endl << s.fullname << endl;
        io1 << endl << s.fullname << endl;
        strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", timeInfo);
        io << timeBuffer << "   ";
        io1 << timeBuffer << "   ";

        strftime(timeBuffer, sizeof(timeBuffer), "%d-%m-%Y", timeInfo);
        io << timeBuffer << endl;
        io1 << timeBuffer << endl;

        cout << "Write Post from here ...." << endl << endl;
        cin.ignore();
        while (true) {
            getline(cin, write_post);

            if (write_post.empty())
                break;
            io << write_post << endl;
            io1 << "Posts :" << endl << endl;
            io1 << write_post << endl;
        }
        io << endl;
        io1 << endl;
        io.close();
        io1.close();
    }
};

class Profile : virtual public start, virtual public setting, virtual public write {
public:
    void access(start s, setting sd, write ww) {
        string txt = s.fname + "_" + s.lname + ".txt";
        ifstream in;
        in.open(txt.c_str(), ios::in);



        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }

        in.close();
    }
};

class home {
public:
    //friend function declaration
    friend void fb_post(home h);
};
//friend function definition
void fb_post(home h) {
    ifstream of("post.txt");
    string linee;
    while (getline(of, linee)) {
        cout << linee << endl;
    }

    of.close();
}
//class friends inherits start class virtually
class friends : virtual public start {
public:
    void friendss(start sss) {
        ifstream fs("friends.txt");
        string lin;
        int i = 1, nn;
        while (!fs.eof()) {
            getline(fs, lin);
            cout << i << ". " << lin << endl << endl;
            cout << "1.Add friend" << endl << "2.Skip " << endl;
            cin >> nn;
            if (nn == 1) {
                cout << "Friend request sent" << endl;
                sss.friendRequestsQueue.push(lin);
                ofstream mes;
                string d = "message_" + lin + "_" + sss.fname + ".txt";
                mes.open(d.c_str(), ios::out);
                mes << sss.fullname << " sent you a friend request" << endl
                    << "1.Accept " << endl
                    << "2.Reject" << endl;
            }

            i++;
        }
        fs.close();
    }
};
//class friendlist inherits start class virtually
class friendlist : virtual public start {
protected:
    string str, write_msg;

public:
    void listt(start dd) {
        ifstream fs("friends.txt");
        string fr;
        int i = 1, nn;
        while (!fs.eof()) {
            getline(fs, fr);
            cout << i << ". " << fr << endl << endl;
            cout << "1. Message" << endl << "2. See profile " << endl;
            cin >> nn;
            if (nn == 1) {
                str = "message_" + fr + "_" + dd.fname + ".txt";
                ofstream bb;
                bb.open(str.c_str(), ios::app);
                cout << "Write Message :" << endl;
                bb << dd.fullname << " : ";
                cin.ignore();
                while (true) {
                    getline(cin, write_msg);
                    if (write_msg.empty())
                        break;
                    bb << write_msg << endl;
                }
                bb << endl;
                bb.close();
            }
            if (nn == 2) {
                string oop = fr + ".txt", strr;
                ifstream im;
                im.open(oop.c_str(), ios::in);
                while (!im.eof()) {
                    getline(im, strr);
                    cout << strr;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int n, a, choice;
    string em, ph, pas;
    setting setp;
    start s;
    write w;
    Profile p;
    home h;
    friends f;
    friendlist fl;
     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = {0, 0, 120, 120};
    SetConsoleWindowInfo(console, TRUE, &rect);

cout<<"                                     =========================================="<<endl;
cout<<"                                                Text only Facebook"<<endl;
cout<<"                                     =========================================="<<endl;
l1:

    cout << endl <<     "                                     1.Sign Up" << endl << "                                     2.Log in" << endl;
    cin >> n;
    if (n == 1) {
        system("cls");
        s.getdata();

        Sleep(1600);
    l4:
        system("cls");
        cout<<endl<<endl<<endl;
        cout << "                                        Facebook" << endl<<endl;
        cout<<"                                     ";
        for(int i=0;i<20;i++)
        {
            cout<<"|";
            Sleep(100);
        }

        system("cls");
        switch (1) {
        case 1:
            cout << "                                     1. Home" << endl
                << "                                     2. My profile" << endl
                << "                                     3. Write post" << endl
                << "                                     4. See friendlist" << endl
                << "                                     5. Find friends" << endl
                << "                                     6. Setting profile " << endl
                << "                                     7. Delete Account" << endl;
            cout <<endl<< "                                     Enter choice: ";
            cin >> choice;
            system("cls");
            switch (choice) {
            case 1:
                fb_post(h);
                   char ch2;

        cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;

            case 3:
                w.post(s);
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;
       m1:     case 6:

                int c;
                setp.tx(s);
                setp.nam(s);
                setp.show();
                cout << "                                     1.Add Bio" << endl
                    << "                                     2.Add University/College" << endl
                    << "                                     3.Add Workplace" << endl
                    << "                                     4.Add Current city" << endl
                    << "                                     5.Add Hometown" << endl;
            l2:
                cin >> c;
                if (c == 1) {
                    setp.bio();
                    goto l2;
                }
                if (c == 2) {
                    setp.uni();
                    goto l2;
                }

                if (c == 3) {
                    setp.work();
                    goto l2;
                }

                if (c == 4) {
                    setp.cucity();
                    goto l2;
                }

                if (c == 5) {
                    setp.homett();
                }
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;
            case 2:
goto m1;
                p.access(s, setp, w);
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;
            case 4:
                fl.listt(s);
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;
            case 5:
                f.friendss(s);
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;

            case 7:
                string fnn, lnn, eee, pp;
                delete_ac ob1;
                cout << "                                     Enter first name :";
                cin >> fnn;
                cout << "                                     Enter Last name :";
                cin >> lnn;
                cout << "                                     Enter your email address :";
                cin >> eee;
                cout << "                                     Enter your password :";
                cin >> pp;
                delete_ac ob2(fnn, lnn, eee, pp);
                  cout << "Press [Space] to return to the start page: ";
        ch2 = _getch();
        if (ch2 == ' ')
            goto l4;
                break;
            }
        }

        char ch1;
        cout << "Press [Space] to return to the main menu: ";
        ch1 = _getch();
        if (ch1 == ' ')
            goto l1;
    }
    if (n == 2) {
        system("cls");
        log_in(s);
        Sleep(1000);
        goto l4;

    }
    return 0;
}


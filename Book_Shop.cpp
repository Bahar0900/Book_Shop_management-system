#include<bits/stdc++.h>
using namespace std;

class Book_Shop{
protected:
    string author,title,publisher;
    double price;
    int stock;
public:
    Book_Shop(){}
    Book_Shop(string t,string a,string p,double m,int s){

        title=t;
        author=a;
        publisher=p;
        price =m;
        stock =s;
    }
    double have(Book_Shop book){
        return book.price;
    }
    int Copy(Book_Shop book){
        return book.stock;
    }

    void Book_details(Book_Shop book){
        system("cls");
        cout <<"\n\tBook Details " << endl;
        cout << "\nBook title : " << book.title << endl;
        cout << "Book author : " << book.author << endl;
        cout << "Book publisher : " << book.publisher << endl;
        cout << "Book price : " << book.price << endl<< endl;
        return;
    }
    void show_book(Book_Shop book){
        cout << book.title <<"        " << book.author << endl;
    }
    string gettitle(){return title;}
    string getauthor(){return author;}
    string getpub(){return publisher;}
    double getcost(){return price;}
    int getss(){return stock;}
    ~Book_Shop(){};
    friend int Find (string,string);
};
class Customer: protected Book_Shop{

public:
      Customer(){}
      void details(Book_Shop book,int x){

        show_book(book);
    }
    void details(Book_Shop book){
        Book_details(book);
    }
};
class Admin: protected Book_Shop{
public:

    Admin(){}
    Admin (string T,string A,string P,double c,int s):Book_Shop(T,A,P,c,s){}
};
vector<Book_Shop> BOOKS;
void write(){
    ofstream out("Information.txt");
    for(auto u: BOOKS){
        out << u.gettitle() <<" " << u.getauthor() << " " << u.getpub() << " " << u.getcost() << " " << u.getss() << endl;
    }
    out.close();
}
int Find(string Author,string Title){
        for(int i=0;i<BOOKS.size();i++){
            if(Author==BOOKS[i].author && Title==BOOKS[i].title) return i;
        }
        return -1;
}

int searching(){

            string title,author;
            cout << "\n\n\nEnter book title : ";
            cin >> title;
            cout << "Enter book author : ";
            cin >> author;

            int position=Find(author,title);

            if(position==-1) {cout << "Sorry , this book is not in the stock!!!";}
            else{
                Customer Book;
                Book.details(BOOKS[position]);
            }

            return position;
}

void buy(int position){
    Book_Shop book;
    int copies=book.Copy(BOOKS[position]);
    double price=book.have(BOOKS[position]);

    cout << "Needed copies : ";
    int cop;cin >> cop;
    if(cop>copies) { cout << " Sorry , this many copies are not available !!" << endl;}
    else{
        cout << "You have to pay " << cop*price << "/=" <<endl << endl;
    }
    cout << "Enter a number to continue: ";
    int n;cin >> n;
    return;
}

void Add_data(){
    system("cls");
    string publisher,author,title;
    double price;
    int stock;

    cout << "\n\n\n\Book title: ";
    cin >> title;
    cout << "Book author : ";
    cin >> author;
    cout << "Book pulisher : ";
    cin >> publisher;
    cout << "Price: ";
    cin >> price;
    cout << "Stock : ";
    cin >> stock;

    Admin data(title,author,publisher,price,stock);
    Book_Shop book(title,author,publisher,price,stock);

    BOOKS.push_back(book);
    //write();
    return;
}
void Update_data(){

    system("cls");
    cout << endl << endl;
    cout << "\n\nEnter Book Title : ";
    string title;cin  >> title;
    cout << "Enter Book Author : ";
    string author;cin >> author;

    int position = Find(title,author);

    cout << "\n\nEnter updated data : " <<endl;
    cout << "\nEnter title : ";
    cin >> title;
    cout << "Enter Author : ";
    cin >> author;
    cout << "Enter publication : " ;
    string publication;cin >> publication;
    cout << "Enter price: " ;
    double price; cin >> price;
    cout << "Enter stock : ";
    int stock;cin >> stock;

    BOOKS[position].~Book_Shop();
    BOOKS.erase(BOOKS.begin()+position);
    Admin book(title,author,publication,price,stock);
    Book_Shop books(title,author,publication,price,stock);
    BOOKS.push_back(books);
    system("cls");
    write();
    };

void Delete_data(){

    system("cls");
    string title,author;
    cout << "Enter title : "; cin >> title;
    cout << "Enter author : " ; cin >> author;

    cout << endl ;
    int position=Find(title,author);
    BOOKS[position].~Book_Shop();
    BOOKS.erase(BOOKS.begin()+position);
    write();

}
bool Admin_LogIn();
bool Customer_LogIn();
bool Customer_SignUp();

///////////------------Main Function Starts---------/////////////


int main(){

    cout << "\n\t\t\t\tSagor's Book Shop" << endl;
    ifstream open("Information.txt",ios:: app);
    string tt,au,pu;
    double pr;
    int st;
    while(!open.eof()){
        open >> tt >> au >> pu >> pr >> st;
        Book_Shop Data(tt,au,pu,pr,st);
        BOOKS.push_back(Data);

    }
    open.close();

    label:
    while(1){
        cout << endl << endl << "------------------------------------Log In------------------------------------------" << endl << endl;
        cout << "                                 1.Admin Log In" << endl;
        cout << "                                 2.Customer Log In" << endl;
        cout << "                                 3.Customer Sign Up" << endl;
        cout << "                                 4. Exit" << endl;
        cout << "                                 Choose a option : ";
        int option; cin >> option;
        system("cls");
        cout << endl << endl;

        int Login_checker_customer=0,Login_checker_Admin=0,customer_signUp_val=0;
        switch(option){
            case 1: Login_checker_Admin=Admin_LogIn();
                    break;
            case 2: Login_checker_customer=Customer_LogIn();
                    break;
            case 3: customer_signUp_val=Customer_SignUp();
                    break;
                    main();
            case 4: {
                cout << "Thanks for coming" << endl;
                exit(0);
            }
            default: cout <<"                                Warning !!! Choose 1/2/3/4";
                    main();
        }
        if(customer_signUp_val==1) {
            system("cls");
            cout << "\n\n\n\t\t\t\tSuccessfully Signed Up" << endl;
            main();
        }

        if(Login_checker_Admin==1){

            //----------Here starts the admin page------------//

            system("cls");
            cout << "\n\n\n\t\t\tCongratulations.Login succesfull!! " << endl<<endl;

            while(1){
                cout <<"\n\n\t\t\t\t----Admin Page----" << endl;

            cout << "\t\t\tPress" << endl;
            cout << "\t\t\t1.Add new data" << endl;
            cout << "\t\t\t2.Update data" << endl;
            cout << "\t\t\t3.Delete data" << endl;
            cout << "\t\t\t4.goto login page"<< endl;

            cout << endl << endl << "\n\t\t\tChoose a option : ";
            cin >> option;

            switch(option){

                case 1: Add_data();
                        system("cls");
                        cout << "\n\n\n\t\t\tNew data added successfully" << endl;
                        break;
                case 2: Update_data();
                        system("cls");
                        cout << "\n\n\n\t\t\tData updated successfully" << endl;
                        break;
                case 3:Delete_data();
                        system("cls");
                        cout << "\n\n\n\t\t\tData deleted successfully" << endl;
                        break;
                case 4:
                        system("cls");
                        goto label;

                default:
                    system("cls");
                    cout << "\n\n\t\t\tWarning !!! Choose 1/2/3/4" << endl;
                    continue;
                }


            }

        }
        else if(Login_checker_customer==1){

            system("cls");
            //---------------This is customer Page-----------------//
            cout << "\n\n\n\t\t\tCongratulations.Login succesfull!! " << endl<<endl;

            while(1){


            cout <<"\n\n\t\t\t\t----Customer Page----" << endl;

            cout << "\t\t\tPress" << endl;
            cout << "\t\t\t1.See All Books" << endl;
            cout << "\t\t\t2.Search for books" << endl;
            cout << "\t\t\t3.goto login page"<< endl;
            cout << endl << endl << "\n\t\t\tChoose a option : ";
            cin >> option;
            switch(option){

                case 1:  {
                            system("cls");

                            cout << endl << "Book Title        " << "Author" << endl;
                            for(auto u:BOOKS){

                                Customer customer;
                                customer.details(u,2);
                            }
                            cout << "\n\n\t\t\tPress 1 to goto customer page : ";
                            cin >> option;
                            if(option ==1) {system("cls");continue;}
                         }
                case 2: {
                            system("cls");
                            int position = searching();
                            cout << "\n\n\t\tPress 1 to goto customer page ";
                            if(position!=-1)cout << "\n\t\tPress 2 to buy : ";

                            cin >> option;
                            if(option ==1) {system("cls");continue;}
                            else {
                                buy(position);


                                system("cls");
                                continue;
                            }

                        }
                case 3:
                    system("cls");
                    main();

                default:
                    system("cls");
                    cout << "\n\n\n\t\t\t\tWarning!!! Choose 1/2/3" << endl;

            }

            }

        }
        else {
            system("cls");
            cout << "\n\n\n\t\t\tSorry Your do not have an account." << endl;
            if(option==2) cout <<"\t\t\tSign Up first." << endl;
            main();
        }
    }

}


/////--------------------main function ends-----------------//////////


bool Admin_LogIn(){

    cout << "----------------------------------------Admin LogIn---------------------" << endl << endl;
    ifstream input("Admin_input.txt",ios::app);
    string Admin_Name,Admin_pass;
    cout << "Enter your name : ";
    cin >> Admin_Name;
    cout << "Enter your password : ";
    cin >> Admin_pass;

    string name,pass;input >> name >> pass;
    while(!input.eof()){
        if(name==Admin_Name && pass==Admin_pass)
        {
            input.close();
            return 1;
        }
        input >> name >> pass;
    }
    input.close();
    return 0;

}
bool Customer_LogIn(){

    cout << "----------------------------------------Customer LogIn---------------------" << endl << endl;
    ifstream input("Customer_input.txt",ios::app);
    string customer_name,customer_pass;
    cout << "Enter your name : ";
    cin >> customer_name;
    cout << "Enter your password : ";
    cin >> customer_pass;

    string name,pass;input >> name >> pass;
    while(!input.eof()){
        if(name==customer_name && pass==customer_pass)
        {
            input.close();
            return 1;
        }
        input >> name >> pass;
    }
    input.close();
    return 0;
}

bool Customer_SignUp(){

    cout << "----------------------------------------Customer SignUp---------------------" << endl << endl;
    ofstream out("Customer_input.txt",ios::app);

    string name,pass;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter your password : ";
    cin >> pass;

    out << name << " " << pass << endl;
    out.close();

    return 1;
}


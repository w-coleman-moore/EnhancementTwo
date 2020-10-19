// EnhancedCodeAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Features:

// 1. Administrator mode: There are two modes in this project – the administrator mode and the user mode.
//    For the first time you have to create Users from the Admin mode. Once users are created, you can use the
//    same user again and again, and they will be stored in separate files.
//    The operations related to both these modes are quite similar in this railway reservation system project
//    in C++. In Admin mode, you can create detail database, add details, display details, perform user management
//    functions and display passenger details.
// 2. User mode: As aforementioned, at first you need to go to the administrator mode and create users. After
//    that, you can use these users as you wish, and the information related to them will be recorded in separate
//    files. In the user mode, you can create id database, add details and display details.
// 3. Train and Reservation details: In this railway reservation system project in C++, users can get both the
//    train details and the train reservation details. The details to be provided for train are train no., train
//    name, boarding point, destination point, no. of seats in first class and fare per ticket, no. of seats in
//    second class and fare per ticket and date of travel.
//    And, in case of reservation details, the information to be provided are train no., train name, boarding
//    point, destination point, no. of seats required, seat class specification, date of reservation, passenger
//    category and amount to be paid. According to the no. of seats, additional information – passenger name and
//    passenger age are to be provided. The passenger category is divided as: military, senior citizen, children and none.
// 4. Cancel reservation: It is somewhat similar to the feature mentioned above. This feature requires the date of
//    cancellation in this railway reservation system project in C++. Then cancellation details can be displayed;
//    the details here include train no., train name, boarding point, destination point, passenger class, no. of
//    seats to be cancelled, passenger name and age, date of cancellation and the amount to be collected back.
// 5. Password: This railway reservation system project in C++ requires the administrator password to access
//    the admin mode. The password is “codewithc”. If you enter the wrong password, it displays the
//    message – “You are not permitted to login.”
//
//    The comments above come from the Railway Reservation Website: https://www.codewithc.com/railway-reservation-system-project-in-c/

//#include "stdafx.h"
#include "pch.h"

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include<time.h>
#include<iomanip>
#include<fstream>

using namespace std;

char f[10] = "f";
char s[10] = "s";
int addr, ad, flag, f1, d, m, i, amt;
float tamt;

// getid() in class login
static const char* strID = "Enter your id:";
static const char* strPW = "Enter the password:";

//
static const char* strID2 = "Id:";
static const char* strPW2 = "Password:";

// class detail
static const char* strDET1 = "Enter the details as follows\n";
static const char* strTRNNO = "Train no:";
static const char* strTRNNM = "Train name:";
static const char* strBRDPT = "Boarding point:";
static const char* strDSTPT = "Destination pt:";
static const char* strST1ST = "No of seats in first class & fare per ticket:";
static const char* strST2ND = "No of seats in second class & fare per ticket:";
static const char* strDATTRV = "Date of travel:";

// class reser
static const char* str1ST2ND = "Enter the class f-first class s-second class:";
static const char* strCONCAT = "Enter the concession category\n";
static const char* strCONLST1 = "1.Military\n2.Senior citizen\n";
static const char* strCONLST2 = "3.Children below 5 yrs\n4.None\n";
static const char* strDETEND = "............END OF GETTING DETAILS............\n";
static const char* strSTREQ = "No of seats required:";
static const char* strPASNM = "Passenger name:";
static const char* strPASAG = "Passenger age:";
static const char* strDASH = "...............................................\n";
static const char* strPNR = "Pnr no:";
static const char* strTRNNUM = "\nTrain no:";
static const char* strTRNNAM = "\nTrain name:";
static const char* strYRCLS = "\nYour class:";
static const char* strDATRES = "\nDate of reservation:";
static const char* strCONCAT2 = "\nYour concession category:";
static const char* strYOUPAY = "\nYou must pay:";
static const char* strSTAR = "***********************************************\n";
static const char* strENDRES = ".........END OF RESERVATION.................\n";

// class canc
static const char* strDATCANC = "Date of cancellation:";
static const char* strENDDET = "...........END OF GETTING DETAILS...........\n";
static const char* strSTCANC = "no of seats to be cancelled:";
static const char* strDATCANC2 = "\nDate of cancellation:";
static const char* strYRCOLL = "\nDate of cancellation:";
static const char* strENDCANC = ".........END OF CANCELLATION.............\n";

// main
static const char* strTILDE = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
static const char* strMAINTITLE = ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
static const char* strMAINMENU = "1.Admin mode\n2.User mode\n3.Exit\n";
static const char* strMAINCHCE = "Enter your choice:";

// database
static const char* strPASSWD = "codewithc";
static const char* strWRGPASSWD = "Enter the password correctly \n";
static const char* strPASSWDPMT = "You are not permitted to logon this mode\n";
static const char* strADMENU1 = "...........ADMINISTRATOR MENU...........\n";
static const char* strADMENU2 = "1.Create detail data base\n2.Add details\n";
static const char* strADMENU3 = "3.Display details\n4.User management\n";
static const char* strADMENU4 = "5.Display passenger details\n6.Return to main menu\n";
static const char* strADMENU5 = "Enter your choice:";
static const char* strADDREC = "Do you want to add one more record?\n";
static const char* strYorN = "y-for Yes\nn-for No\n";

// reserve
static const char* strRSVMENU = "1.Reserve\n2.Return to the main menu\n";

// res
static const char* strCONCATMIL = "Concession category:MILITARY PERSONNEL\n";
static const char* strCONCATSEN = "Concession category:SENIOR CITIZEN\n";
static const char* strCONCATU5 = "Concession category:CHILDERN BELOW FIVE\n";
static const char* strNOCON = "You cannot get any concession\n";
static const char* strTICHEAD1 = "--------------Your ticket is reserved-----------\n";
static const char* strTICHEAD2 = "-----------------End of reservation menu-------\n";
static const char* strNOSEATS = "**********Sorry req seats not available********\n";
static const char* strENDRESV = "------------End of reservation---------\n";
static const char* strWRGTRN = "............Wrong train no......................\n";
static const char* strENTTRN = "......Enter the train no from the data base.....\n";

// cancell
static const char* strCANMENU1 = "**********CANCELLATION MENU*********\n";
static const char* strCANDATE = "You are cancelling at the date of departure\n";
static const char* strCANMONTH = "You are cancelling at the month of departure\n";
static const char* strCANMONTH1 = "You are cancelling one month before the date of departure\n";
static const char* strCANAFTER = "Cancelling after the departure\n";
static const char* strCANNOTCOMP = "Your request cannot be completed\n";
static const char* strENTPNR = "Enter the correct pnr no\n";

// can
static const char* strCANMENU2 = ".................CANCELLATION MENU.........\n";
static const char* strCANMENU3 = "1.Cancell\n2.Return to the main menu\n";
static const char* strCANMENU4 = "Enter your choice:";

// user
static const char* strUSERMENU2 = "***********WELCOME TO THE USER MENU**\n";
static const char* strENTPASSWD = "Enter your password:";
static const char* strUSERMENU3 = "1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
static const char* strUSERMENU4 = "Enter your choice:";
static const char* strUSERMENU5 = "Enter your user id and password correctly\n";

// manage
static const char* strUSERMGTMENU1 = ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
static const char* strUSERMGTMENU2 = "1.Create id data base\n2.Add details\n";
static const char* strUSERMGTMENU3 = "3.Display details\n4.Return to the main menu\n";
static const char* strUSERMGTMENU4 = "Enter your choice:";
static const char* strUSERMGTADDREC = "Do you want to add one more record\n";
static const char* strGETYorN = "y-Yes\nn-No\n";

class login
{
public:
   static const int idLEN = 100;
   char id[idLEN];
   static const int passLEN = 100;
   char pass[passLEN];
   char *password;
   static const int pwsLEN = 20;
   char pwstring[pwsLEN];

   void getid()
   {
      cout << strID;
      gets_s(id, idLEN - 1);
      // get up to pwsLEN-1 characters as returned password
      password = getpass((char*)strPW);
      // source can hold up to 19 characters
      // destination can hold up to 99 characters
      // use length of shorter source string when copying
      strcpy_s(pass, pwsLEN, password);
   }

   // display the prompt to the user
   // get up to pwsLEN-1 characters from user as the password
   // return pointer to password string to calling function
   // returned string can be up to 19 characters plus terminator
   char *getpass(char *prompt)
   {
      cout << prompt;
      gets_s(pwstring, pwsLEN - 1);
      return (pwstring);
   }

   // display the user id and the password
   void displayid()
   {
      cout << strID2;     // "Id:"
      puts(id);
      cout << strPW2;     // "Password:"
      puts(pass);
   }
};

// The details to be provided for train are train no.,
// train name, boarding point, destination point, no.
// of seats in first class and fare per ticket, no.
// of seats in second class and fare per ticket and date of travel.

class detail
{
public:
   int tno;
   static const int tnameLEN = 100;
   char tname[tnameLEN];
   static const int bpLEN = 100;
   char bp[bpLEN];
   static const int destLEN = 100;
   char dest[destLEN];
   int c1, c1fare;
   int c2, c2fare;
   int d, m, y;

   void getdetail()
   {
      cout << strDET1;                   // "Enter the details as follows\n"
      cout << strTRNNO;                  // "Train no:"
      cin >> tno;
      cout << strTRNNM;                  // "Train name:"
      gets_s(tname);
      cout << strBRDPT;                  // "Boarding point:"
      gets_s(bp);
      cout << strDSTPT;                  // "Destination pt:"
      gets_s(dest);
      cout << strST1ST;                  // "No of seats in first class & fare per ticket:"
      cin >> c1 >> c1fare;               // --- get number of seats from user
      cout << strST2ND;                  // "No of seats in second class & fare per ticket:"
      cin >> c2 >> c2fare;               // --- get number of seats from user
      cout << strDATTRV;                 // "Date of travel:"
      cin >> d >> m >> y;
   }

   // display train number, train name, boarding point, destination point
   // 1st class and fare, 2nd class and fare
   // day, month and year of travel
   void displaydetail()
   {
      cout << tno << "\t" << tname << "\t" << bp << "\t" << dest << "\t";
      cout << c1 << "\t" << c1fare << "\t" << c2 << "\t" << c2fare << "\t";
      cout << d << "-" << m << "-" << y << "\t" << endl;
   }
};


class reser
{
public:
   int pnr;
   int tno;
   static const int tnameLEN = 100;
   char tname[tnameLEN];
   static const int bpLEN = 10;
   char bp[bpLEN];
   static const int destLEN = 100;
   char dest[destLEN];
   static const int pnamexSIZ = 10;
   static const int pnameySIZ = 100;
   char pname[pnamexSIZ][pnameySIZ];
   static const int ageLEN = 20;
   int age[ageLEN];
   static const int clasLEN = 10;
   char clas[clasLEN];
   int nosr;
   int i;
   int d, m, y;
   int con;


   float amc;

   // reused from class detail
   //static const char* strDET1 = "Enter the details as follows\n";
   //static const char* strTRNNO = "Train no:";
   //static const char* strTRNNM = "Train name:";
   //static const char* strBRDPT = "Boarding point:";
   //static const char* strDSTPT = "Destination pt:";

   void getresdet()
   {
      cout << strDET1;               // "Enter the details as follows\n"
      cout << strTRNNO;              // "Train no:"
      cin >> tno;
      cout << strTRNNM;              // "Train name:"
      gets_s(tname);
      cout << strBRDPT;              // "Boarding point:"
      gets_s(bp);
      cout << strDSTPT;              // "Destination pt:"
      gets_s(dest);
      cout << strSTREQ;              // "No of seats required:"
      cin >> nosr;
      for (i = 0; i < nosr; i++)
      {
         cout << strPASNM;          // "Passenger name:"
         gets_s(pname[i]);
         cout << strPASAG;          // "Passenger age:"
         cin >> age[i];
      }
      cout << str1ST2ND;             // "No of seats in second class & fare per ticket:"
      gets_s(clas);
      cout << strDATTRV;             // "Date of travel:"
      cin >> d >> m >> y;
      cout << (char*)strCONCAT;      // "Enter the concession category\n"
      cout << strCONLST1;            // "1.Military\n2.Senior citizen\n"
      cout << strCONLST2;            // "3.Children below 5 yrs\n4.None\n"
      cin >> con;
      cout << strDETEND;             // "............END OF GETTING DETAILS............\n"
   }

   void displayresdet()
   {
      cout << strDASH;                    // "...............................................\n"
      cout << strDASH;                    // "...............................................\n"
      cout << strPNR << pnr;              // "Pnr no:"
      cout << strTRNNUM << tno;           // "\nTrain no:"
      cout << strTRNNAM;                  // "\nTrain name:"
      puts(tname);
      cout << strBRDPT;                   // "Boarding point:"
      puts(bp);
      cout << strDSTPT;                   // "Destination pt:"
      puts(dest);
      cout << strSTREQ << nosr;           // "No of seats required:"
      for (i = 0; i < nosr; i++)
      {
         cout << strPASNM;               // "Passenger name:"
         puts(pname[i]);
         cout << strPASAG << age[i];     // "Passenger age:"
      }

      cout << strYRCLS;                                  // "\nYour class:"
      puts(clas);
      cout << strDATRES << d << "-" << m << "-" << y;    // "\nDate of reservation:"
      cout << (char*)strCONCAT2 << con;                  // "\nYour concession category:"
      cout << strYOUPAY << amc << endl;                  // "\nYou must pay:"
      cout << strSTAR;                                   // "***********************************************\n"
      cout << strENDRES;                                 // ".........END OF RESERVATION.................\n"
      cout << strSTAR;                                   // "***********************************************\n"
   }
};

class canc
{
public:
   int pnr;
   int tno;
   static const int tnameLEN = 100;
   char tname[tnameLEN];
   static const int bpLEN = 100;
   char bp[bpLEN];
   static const int destLEN = 100;
   char dest[destLEN];
   static const int pnamexSIZ = 10;
   static const int pnameySIZ = 100;
   char pname[pnamexSIZ][pnameySIZ];
   static const int ageLEN = 20;
   int age[ageLEN];
   int i;
   static const int clasLEN = 10;
   char clas[clasLEN];
   int nosc;
   int d, m, y;
   float amr;

   void getcancdet()
   {
      cout << strDET1;             // "Enter the details as follows\n"
      cout << strPNR;              // "Pnr no:"
      cin >> pnr;                  // --- get id from user
      cout << strDATCANC;          // "Date of cancellation:"
      cin >> d >> m >> y;          // --- get day, month, year from user
      cout << strENDDET;           // "...........END OF GETTING DETAILS...........\n"
   }

   void displaycancdet()
   {
      cout << strDASH;
      cout << strDASH;
      cout << strPNR << pnr;
      cout << strTRNNUM << tno;
      cout << strTRNNAM;
      puts(tname);
      cout << strBRDPT;
      puts(bp);

      cout << strDSTPT;                     // "Destination pt:"
      puts(dest);
      cout << strYRCLS;                     // "\nYour class:"
      puts(clas);
      cout << strSTCANC << nosc;            // "no of seats to be cancelled:"
      for (i = 0; i < nosc; i++)
      {
         cout << strPASNM;                 // "Passenger name:"
         puts(pname[i]);
         cout << strPASAG << age[i];       // "Passenger age:"
      }
      cout << strDATCANC2 << d << "-" << m << "-" << y;    // "\nDate of cancellation:"
      cout << strYRCOLL << amr << "rs" << endl;            // "\nDate of cancellation:"
      cout << strSTAR;                                     // "***********************************************\n"
      cout << strENDCANC;                                  // ".........END OF CANCELLATION.............\n"
      cout << strSTAR;                                     // "***********************************************\n"
   }
};

// function prototypes for the functions that follow
void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

// entry point of railway reversation system

int main()
{
   system("clear");  // clrscr();
   int ch;
   cout << strTILDE;                   // "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
   cout << strMAINTITLE;               // ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n"
   cout << strTILDE;                   // "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

   // changed the do/while loop to a while(true)
   // loop. the do/while had invalid exit conditions
   // where only 3 exited the program and where
   // numbers like 0 just stayed in the loop but
   // were not operated on
   while (true)
   {
      cout << strMAINTITLE;           // ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n"
      cout << strMAINMENU;            // "1.Admin mode\n2.User mode\n3.Exit\n"
      cout << strMAINCHCE;            // "Enter your choice:"
      cin >> ch;
      cout << endl;
      switch (ch)

      {
      case 1:                 // admin mode
         database();
         break;
      case 2:                 // user mode
         user();
         break;
      default:
      case 3:                 // exit the program
         exit(0);
      }
   }
}

void database()
{
   login lg;

   char *password;
   char *pass = (char*)strPASSWD;
   password = lg.getpass((char*)strPASSWDPMT);
   detail a;                                                   // instantiate the detail class
   fstream f;
   int ch;

   // check password, if invalid display wrong password
   // and request the user to enter another password
   if (strcmp(pass, password) != 0)
   {
      cout << strWRGPASSWD;
      cout << strPASSWDPMT;
      return; // goto h;
   }

   // check password, if successful then
   if (strcmp(pass, password) == 0)
   {
      char c;
      do
      {
         cout << strADMENU1;             // "...........ADMINISTRATOR MENU...........\n"
         cout << strADMENU2;             // "1.Create detail data base\n2.Add details\n"
         cout << strADMENU3;             // "3.Display details\n4.User management\n"
         cout << strADMENU4;             // "5.Display passenger details\n6.Return to main menu\n"
         cout << strADMENU5;             // "Enter your choice:"
         cin >> ch;                      // get input from user
         cout << endl;

         // switch on user input request
         switch (ch)
         {
            // create detail database
         case 1:
            f.open("t.txt", ios::out | ios::binary);          // open the detail database
            do
            {
               a.getdetail();                                // get the details
               f.write((char *)& a, sizeof(a));              // add to the database
               cout << strADDREC;                            // "Do you want to add one more record?\n"
               cout << strYorN;                              // "y-for Yes\nn-for No\n"
               cin >> c;
            } while (c == 'y');
            f.close();
            break;
            // add details
         case 2:
            f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);   // open the detail database
            a.getdetail();                                                  // add the details
            f.write((char *)& a, sizeof(a));
            f.close();
            break;
            // display details
         case 3:
            f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);   // open the detail database
            f.seekg(0);                                                     // go to the start of the file
            while (f.read((char *)& a, sizeof(a)))
            {
               a.displaydetail();                                          // display the details
            }
            f.close();
            break;
            // user management
         case 4:
            manage();
            break;
            // display passenger details
         case 5:
            displaypassdetail();
            break;
         }
      } while (ch <= 5);

      f.close();
   }
   //	h:
}

// In case of reservation details, the information to be
// provided are train no., train name, boarding point,
// destination point, no.of seats required, seat class
// specification, date of reservation, passenger category
// and amount to be paid.According to the no.of seats,
// additional information ? passenger name and passenger
// age are to be provided.The passenger category is
// divided as : military, senior citizen, children and none.

void reserve()
{
   int ch;
   do
   {
      cout << strRSVMENU;                          // "1.Reserve\n2.Return to the main menu\n"
      cout << strADMENU5;                          // "Enter your choice:"
      cin >> ch;
      cout << endl;
      switch (ch)
      {
      case 1:
         res();                                   // process the reservation request
         break;
      }
   } while (ch == 1);
   (void)_getch();
}

void res()
{
   detail a;              // instantiate the detail class
   reser b;               // instantiate the reservation class
   fstream f1, f2;
   time_t t;
   f1.open("t.txt", ios::in | ios::out | ios::binary);                  // list of trains
   f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);       // list of passengers
   // get the reservation details
   b.getresdet();

   // read the train list
   while (f1.read((char *)&a, sizeof(a)))
   {
      // if train number == reservation train number
      if (a.tno == b.tno)
      {
         // if this is our reservation class == first class
         if (strcmp(b.clas, f) == 0)
         {
            // if # of seats matches the reservation seats
            if (a.c1 >= b.nosr)

            {
               amt = a.c1fare;
               addr = (int)f1.tellg();
               ad = sizeof(a.c1);
               f1.seekp(addr - (7 * ad));
               a.c1 = a.c1 - b.nosr;
               f1.write((char *)& a.c1, sizeof(a.c1));

               // military concession 50% rate
               if (b.con == 1)
               {
                  cout << strCONCATMIL;

                  //b.amc = b.nosr*((amt * 50) / 100);
                  b.amc = (float)b.nosr*((float)amt * (float)0.50);
               }

               // senior citizen concession 60% rate
               else if (b.con == 2)
               {
                  cout << strCONCATSEN;
                  //b.amc = b.nosr*((amt * 60) / 100);
                  b.amc = (float)b.nosr*((float)amt * (float)0.60);
               }

               // children under 5 years old concession FREE
               else if (b.con == 3)
               {
                  cout << strCONCATU5;
                  b.amc = 0.0;
               }

               // everyone else concession FULL PRICE
               else if (b.con == 4)
               {
                  cout << strNOCON;
                  b.amc = (float)b.nosr*(float)amt;
               }
#if 0
               srand((unsigned)time(&t));                          // seed the random number generator
               b.pnr = rand();                                     // generate a random number
#else
               struct timespec ts;
               if (timespec_get(&ts, TIME_UTC) == 0) {
                  /* Handle error */
               }
               srandom(ts.tv_nsec ^ ts.tv_sec);  /* Seed the PRNG */
               /* ... */
               r = random();  /* Generate a random integer */

#endif
               f2.write((char *)& b, sizeof(b));                   // update the reservations
               b.displayresdet();
               cout << strDASH;                // "...............................................\n"
               cout << strTICHEAD1;            // "--------------Your ticket is reserved-----------\n
               cout << strTICHEAD2;            // "-----------------End of reservation menu-------\n"
            }
            else
            {
               cout << strNOSEATS;             // "**********Sorry req seats not available********\n"

            }
         }
         // if this is our reservation class == second class
         else if (strcmp(b.clas, s) == 0)
         {
            if (a.c2 >= b.nosr)
            {
               amt = a.c2fare;
               addr = (int)f1.tellg();
               ad = sizeof(a.c2);
               f1.seekp(addr - (5 * ad));
               a.c2 = a.c2 - b.nosr;
               f1.write((char *)& a.c2, sizeof(a.c2));
               // military concession 50% rate
               if (b.con == 1)
               {
                  cout << strCONCATMIL;
                  //b.amc = b.nosr*((amt * 50) / 100);
                  b.amc = (float)b.nosr*((float)amt * (float)0.50);
               }
               // senior citizen concession 60% rate
               else if (b.con == 2)
               {
                  cout << strCONCATSEN;
                  //b.amc = b.nosr*((amt * 60) / 100);
                  b.amc = (float)b.nosr*((float)amt * (float)0.60);
               }
               // // children under 5 years old concession FREE
               else if (b.con == 3)
               {
                  cout << strCONCATU5;
                  b.amc = 0.0;
               }
               // everyone else concession
               else if (b.con == 4)
               {
                  cout << strNOCON;
                  b.amc = (float)b.nosr*(float)amt;
               }
               f2.write((char *)& b, sizeof(b));     // update the reservations
               b.displayresdet();
               cout << strDASH;                // "...............................................\n"
               cout << strTICHEAD1;            // "--------------Your ticket is reserved-----------\n
               cout << strENDRESV;             // "------------End of reservation---------\n"
            }
            else


            {
               cout << strNOSEATS;             // "**********Sorry req seats not available********\n"
            }
         }
         (void)_getch();

         return; // goto end;
      }
      else
      {
         flag = 0;
      }
   } // end of while()

   if (flag == 0)
   {
      cout << strWRGTRN;            // "............Wrong train no......................\n"
      cout << strENTTRN;            // "......Enter the train no from the data base.....\n"
   }
   f1.close();
   f2.close();
   (void)_getch();
   //	end:
}

void displaypassdetail()
{
   fstream f;
   reser b;            // instantiate reservation class
   f.open("p.txt", ios::in | ios::out | ios::binary);
   // go to the start of the file
   f.seekg(0);
   while (f.read((char *)& b, sizeof(b)))                  // read the reservation file
   {
      b.displayresdet();                                  // display the reservations
   }
   f.close();
   (void)_getch();
}

void enquiry()
{

   fstream f;
   f.open("t.txt", ios::in | ios::out | ios::binary);             // open the file
   detail a;
   while (f.read((char *)& a, sizeof(a)))
   {
      a.displaydetail();                                         // display the reservation details
   }
   (void)_getch();
}

// This function requires the date of cancellation in this railway
// reservation system project. Then cancellation details can
// be displayed; the details here include train no., train name,
// boarding point, destination point, passenger class, no.of seats
// to be cancelled, passenger name and age, date of cancellation
// and the amount to be collected back.

void cancell()
{
   detail a;
   reser b;
   canc c;
   fstream f1, f2, f3;
   f1.open("t.txt", ios::in | ios::out | ios::binary);      // details database
   f2.open("p.txt", ios::in | ios::out | ios::binary);      // passenger database
   f3.open("cn.txt", ios::in | ios::out | ios::binary);     //
   cout << strCANMENU1;                                     // "**********CANCELLATION MENU*********\n"
   c.getcancdet();                                          // get the cancellation details
   while (f2.read((char *)& b, sizeof(b)))
   {
      // if reservation == cancellation
      if (b.pnr == c.pnr)
      {
         c.tno = b.tno;
         strcpy_s(c.tname, c.tnameLEN, b.tname);
         strcpy_s(c.bp, c.bpLEN, b.bp);
         strcpy_s(c.dest, c.destLEN, b.dest);
         c.nosc = b.nosr;
         for (int j = 0; j < c.nosc; j++)                           // release all the seats of the reservation
         {
            strcpy_s(c.pname[j], c.pnamexSIZ, b.pname[j]);
            c.age[j] = b.age[j];
         }
         strcpy_s(c.clas, c.clasLEN, b.clas);
         if (strcmp(c.clas, f) == 0)                                // release the first class seats
         {
            while (f1.read((char *)& a, sizeof(a)))
            {

               if (a.tno == c.tno)
               {
                  a.c1 = a.c1 + c.nosc;
                  d = a.d;
                  m = a.m;
                  addr = (int)f1.tellg();
                  ad = sizeof(a.c1);
                  f1.seekp(addr - (7 * ad));
                  f1.write((char *)& a.c1, sizeof(a.c1));
                  tamt = b.amc;
                  if ((c.d == d) && (c.m == m))
                  {
                     cout << strCANDATE;                             // "You are cancelling at the date of departure\n"
                     c.amr = tamt - ((tamt * 60) / 100);             // you get 40% refund
                  }
                  else if (c.m == m)
                  {
                     cout << strCANMONTH;                            // "You are cancelling at the month of departure\n"
                     c.amr = tamt - ((tamt * 50) / 100);             // you get 50% refund
                  }
                  else if (m > c.m)
                  {
                     cout << strCANMONTH1;                           // "You are cancelling one month before the date of departure\n"
                     c.amr = tamt - ((tamt * 20) / 100);             // you get 80% refund
                  }
                  else
                  {
                     cout << strCANAFTER;                            // "Cancelling after the departure\n"
                     cout << strCANNOTCOMP;                          // "Your request cannot be completed\n"
                  }
                  c.displaycancdet();
                  goto h;
               }
            }
         }
         else if (strcmp(c.clas, s) == 0)                           // release the second class seats
         {
            // read the details database until end-of-file is reached
            while (f1.read((char *)& a, sizeof(a)))
            {
               // search for train number in database
               if (a.tno == c.tno)
               {
                  a.c2 = a.c2 + c.nosc;                            // compute total cost of the seats to be cancelled
                  d = a.d;                                         // get the day of the month
                  m = a.m;                                         // get the month
                  addr = (int)f1.tellg();
                  ad = sizeof(a.c2);
                  f1.seekp(addr - (5 * ad));
                  f1.write((char *)& a.c2, sizeof(a.c2));          // update the details
                  tamt = b.amc;
                  if ((c.d == d) && (c.m == m))
                  {
                     cout << strCANDATE;                             // "You are cancelling at the date of departure\n"
                     c.amr = tamt - ((tamt * 60) / 100);             // you get 40% refund
                  }
                  else if (c.m == m)
                  {
                     cout << strCANMONTH;                            // "You are cancelling at the month of departure\n"
                     c.amr = tamt - ((tamt * 50) / 100);             // you get 50% refund
                  }
                  else if (m > c.m)
                  {
                     cout << strCANMONTH1;                           // "You are cancelling one month before the date of departure\n"
                     c.amr = tamt - ((tamt * 20) / 100);             // you get 80% refund
                  }
                  else
                  {
                     cout << strCANAFTER;                           // "Cancelling after the departure\n"
                     cout << strCANNOTCOMP;                         // "Your request cannot be completed\n"
                  }
                  goto h;
                  c.displaycancdet();
               }
            }
         }
      }
      else
      {
         flag = 0;

      }
   }
h:
   if (flag == 0)
   {
      cout << strENTPNR;                            // "Enter the correct pnr no\n"
   }
   f1.close();
   f2.close();
   f3.close();
   (void)_getch();
}

void can()
{
   int ch;
   do
   {
      cout << strCANMENU2;           // ".................CANCELLATION MENU.........\n"
      cout << strCANMENU3;           // "1.Cancell\n2.Return to the main menu\n"
      cout << strCANMENU4;           // "Enter your choice:"
      cin >> ch;
      cout << endl;
      switch (ch)
      {
      case 1:
         cancell();                 // cancel the reservation
         break;
      }
   } while (ch == 1);
   (void)_getch();
}

void user()
{
   login a;
   int ch;
   cout << strSTAR;                                             // "***********************************************\n"
   cout << strUSERMENU2;                                        // "***********WELCOME TO THE USER MENU**\n"
   cout << strSTAR;                                             // "***********************************************\n"
   char *password;

   fstream f;
   f.open("id.txt", ios::in | ios::out | ios::binary);          // open the id database
   static const int idLEN = 100;
   char id[idLEN];
   puts("Enter your id:");                                      // enter your id
   gets_s(id, idLEN - 1);
   password = a.getpass((char*)strENTPASSWD);                   // enter your password
   while (f.read((char *)& a, sizeof(a)))
   {
      // if the IDs and passwords match, then allow access
      if ((strcmp(a.id, id) == 0) && (strcmp(a.pass, password) == 0))
      {
         do
         {
            cout << strUSERMENU3;                // "1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n"
            cout << strUSERMENU4;                // "Enter your choice:"
            cin >> ch;
            cout << endl;
            switch (ch)
            {
            case 1:
               reserve();                        // make reservations
               break;
            case 2:
               cancell();                        // cancel reservations
               break;
            case 3:
               enquiry();                        // make enquiries
               break;
            }
         } while (ch <= 3);
         return; // goto label_j;
      }
      else
      {
         d = 1;
      }
   }
   if (d == 1)
   {
      cout << strUSERMENU5;           // "Enter your user id and password correctly\n"
   }

   (void)_getch();
   // label_j:
}

void manage()
{
   int ch;
   fstream f;
   char c;
   login a;
   cout << strUSERMGTMENU1;          // .........WELCOME TO THE USER MANAGEMENT MENU........\n"
   do
   {
      cout << strUSERMGTMENU2;      // "1.Create id data base\n2.Add details\n"
      cout << strUSERMGTMENU3;      // "3.Display details\n4.Return to the main menu\n"
      cout << strUSERMGTMENU4;      // "Enter your choice:"
      cin >> ch;
      cout << endl;
      switch (ch)
      {
         // Create id database
      case 1:
         f.open("id.txt", ios::out | ios::binary);    // open the id.txt file
         do
         {
            // get the user password
            a.getid();
            f.write((char *)& a, sizeof(a));
            cout << strUSERMGTADDREC;                // "Do you want to add one more record\n"
            cout << strGETYorN;                      // "y-Yes\nn-No\n"
            cin >> c;
         } while (c == 'y');
         f.close();
         break;
         // add details
      case 2:
         f.open("id.txt", ios::in | ios::out | ios::binary | ios::app);    // open the id.txt file
         a.getid();
         f.write((char *)& a, sizeof(a));                                  // write password to file
         f.close();
         break;
         // display details
      case 3:
         f.open("id.txt", ios::in | ios::out | ios::binary);               // open the id.txt fil
         // seek to start of file
         f.seekg(0);
         while (f.read((char *)& a, sizeof(a)))                            // read the stored login record
         {
            a.displayid();                                                // and display it
         }
         f.close();
         break;
      }
   } while (ch <= 3);
   (void)_getch();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

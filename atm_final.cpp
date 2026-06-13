#include <iostream>
#include <string>

int main()
{
    double bnpBalance = 30000;
    double jcashBalance = 6767;

    int newPin = 10111;
    while(true)
    {
        system("cls");
        int tries = 0;
        bool pinCorrect = false;
        bool firstTry = true;

        while(tries < 3)
        {
            int pin;

            if(firstTry)
            {
                std::cout << "+--------------------------------------------+\n";
                std::cout << "        || WELCOME TO MY SIMPLE ATM ||        \n";
                std::cout << "               by: Jeia @2026                 \n";
                std::cout << "+--------------------------------------------+\n";
                std::cout << "[Enter your PIN and press ENTER]\n";
            }

            std::cout << ": ";
            std::cin >> pin;
            std::cout << std::endl;
            firstTry = false;

            if(pin == newPin)
            {
                pinCorrect = true;
                break;
            }
            else
            {
                tries++;
                int remaining = 3 - tries;
                if (remaining > 0)
                {
                    std::cout << "[!] Incorrect PIN. " << remaining << " attempt(s) remaining.\n";
                    std::cout << std::endl;
                }
            }
        }

        if(!pinCorrect)
        {
            std::cout << "+--------------------------------------------+\n";
            std::cout << "           [!] OOF, ACCOUNT LOCKED            \n";
            std::cout << "                Try Again LATER               \n";
            std::cout << "+--------------------------------------------+\n";
            return 0;
        }
        
        bool verified = false;

        std::string fullname, birthday, contact;

        while(!verified)
        {
            system("cls");

            std::cout << "+--------------------------------------------+\n";
            std::cout << "     [Enter Credentials for Verification]     \n";
            std::cout << "+--------------------------------------------+\n";

            std::cout << "Enter FULL NAME: (e.g DELA CRUZ, JUAN A.)\n";
            std::cout << ": ";
            std::getline(std::cin >> std::ws, fullname);

            std::cout << "Enter DATE OF BIRTH: (MM/DD/YY)\n";
            std::cout << ": ";
            std::getline(std::cin >> std::ws, birthday);

            std::cout << "Enter CONTACT NUMBER:\n";
            std::cout << ": ";
            std::getline(std::cin >> std::ws, contact);
            std::cout << std::endl;

            system("cls");
            std::cout << "+--------------------------------------------+\n";
            std::cout << "             [CREDENTIALS REVIEW]             \n";
            std::cout << "+--------------------------------------------+\n";
            std::cout << "  Full Name : " << fullname << '\n';
            std::cout << "  Birthdate : " << birthday << '\n';
            std::cout << "  Contact   : " << contact << '\n';
            std::cout << "+--------------------------------------------+\n";
            std::cout << "   [O] Continue\n";
            std::cout << "   [R] Re-Enter\n";
            std::cout << "   [X] Exit\n";
            std::cout << "+--------------------------------------------+\n";
            std::cout << ": ";
            char credChoice;
            std::cin >> credChoice;
            std::cout << std::endl;

            if(credChoice == 'O' || credChoice == 'o')
                verified = true;
            else if(credChoice == 'X' || credChoice == 'x')
                break;
        }

        if(!verified)
            continue;

        bool atMainMenu = true;
        while(atMainMenu)
        {
            system("cls");
            std::cout << "+--------------------------------------------+\n";
            std::cout << "   Welcome, " << fullname << "!\n";
            std::cout << "   How may I help you today?\n";
            std::cout << "+--------------------------------------------+\n";
            std::cout << "   [O] Continue Transaction\n";
            std::cout << "   [X] Exit\n";
            std::cout << "+--------------------------------------------+\n";
            std::cout << ": ";
            char mainChoice;
            std::cin >> mainChoice;
            std::cout << std::endl;

            if(mainChoice == 'X' || mainChoice == 'x')
            {
                atMainMenu = false;
                continue;
            }

            bool atTransMenu = true;
            while(atTransMenu)
            {
                system("cls");
                std::cout << "+--------------------------------------------+\n";
                std::cout << "             [SELECT TRANSACTION]             \n";
                std::cout << "+--------------------------------------------+\n";
                std::cout << "   [A] Balance Inquiry\n";
                std::cout << "   [B] Withdraw Cash\n";
                std::cout << "   [C] Deposit Cash\n";
                std::cout << "   [D] Change PIN\n";
                std::cout << "   [E] Exit\n";
                std::cout << "+--------------------------------------------+\n";
                std::cout << ": ";
                char transChoice;
                std::cin >> transChoice;
                std::cout << std::endl;

                if(transChoice == 'A' || transChoice == 'a')
                {
                    bool atBalMenu = true;
                    while(atBalMenu)
                    {
                        system("cls");
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "               [BALANCE INQUIRY]              \n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "   [A] Bangko ng Pilipins (BNP)\n";
                        std::cout << "   [B] JCash\n";
                        std::cout << "   [C] Unavailable\n";
                        std::cout << "   [D] Unavailable\n";
                        std::cout << "   [O] Back\n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << ": ";
                        char balChoice;
                        std::cin >> balChoice;
                        std::cout << std::endl;

                        if(balChoice == 'A' || balChoice == 'a')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   Account  : Bangko ng Pilipins (BNP)\n";
                            std::cout << "   Balance  : PHP " << bnpBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   [O] Back\n";
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << ": ";
                            char backChoice;
                            std::cin >> backChoice;
                            std::cout << std::endl;
                        }
                        else if(balChoice == 'B' || balChoice == 'b')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   Account  : JCash\n";
                            std::cout << "   Balance  : PHP " << jcashBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   [O] Back\n";
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << ": ";
                            char backChoice;
                            std::cin >> backChoice;
                            std::cout << std::endl;
                        }
                        else if(balChoice == 'C' || balChoice == 'c' || balChoice == 'D' || balChoice == 'd')
                        {
                            std::cout << "[!] This account slot is unavailable\n";
                            std::cout << "Press Enter to Retry\n";
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if(balChoice == 'O' || balChoice == 'o')
                            atBalMenu = false;
                        else
                        {
                            std::cout << "[!] Invalid option\n";
                            std::cout << std::endl;
                        }
                    }
                }

                else if(transChoice == 'B' || transChoice == 'b')
                {
                    bool atWithdrawMenu = true;
                    while(atWithdrawMenu)
                    {
                        system("cls");
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "                [WITHDRAW CASH]               \n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "   [A] Bangko ng Pilipins (BNP)\n";
                        std::cout << "   [B] JCash\n";
                        std::cout << "   [C] Unavailable\n";
                        std::cout << "   [D] Unavailable\n";
                        std::cout << "   [O] Back\n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << ": ";
                        char wChoice;
                        std::cin >> wChoice;
                        std::cout << std::endl;

                        if(wChoice == 'A' || wChoice == 'a')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Your Balance: PHP " << bnpBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Enter Withdraw Amount: ";
                            double wAmount;
                            std::cin >> wAmount;
                            std::cout << std::endl;

                            if(wAmount > bnpBalance)
                            {
                                std::cout << "[!] Insufficient balance\n";
                                std::cout << "Press Enter to Retry\n";
                                std::cin.ignore();
                                std::cin.get();
                            }
                            else
                            {
                                bnpBalance -= wAmount;
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << "   You withdrew   : PHP " << wAmount << '\n';
                                std::cout << "   Remaining Bal  : PHP " << bnpBalance << '\n';
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << "   [O] Back\n";
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << ": ";
                                char backChoice;
                                std::cin >> backChoice;
                                std::cout << std::endl;
                                atWithdrawMenu = false;
                            }
                        }
                        else if(wChoice == 'B' || wChoice == 'b')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Your Balance: PHP " << jcashBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Enter Withdraw Amount: ";
                            double wAmount;
                            std::cin >> wAmount;
                            std::cout << std::endl;

                            if(wAmount > jcashBalance)
                            {
                                std::cout << "[!] Insufficient balance\n";
                                std::cout << "Press Enter to Retry\n";
                                std::cin.ignore();
                                std::cin.get();
                            }
                            else
                            {
                                jcashBalance -= wAmount;
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << "   You withdrew   : PHP " << wAmount << '\n';
                                std::cout << "   Remaining Bal  : PHP " << jcashBalance << '\n';
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << "   [O] Back\n";
                                std::cout << "+--------------------------------------------+\n";
                                std::cout << ": ";
                                char backChoice;
                                std::cin >> backChoice;
                                std::cout << std::endl;
                                atWithdrawMenu = false;
                            }
                        }
                        else if(wChoice == 'C' || wChoice == 'c' || wChoice == 'D' || wChoice == 'd')
                        {
                            std::cout << "[!] This account slot is unavailable\n";
                            std::cout << "Press Enter to Retry\n";
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if(wChoice == 'O' || wChoice == 'o')
                            atWithdrawMenu = false;
                        else
                        {
                            std::cout << "[!] Invalid option\n";
                            std::cout << std::endl;
                        }
                    }
                }

                else if(transChoice == 'C' || transChoice == 'c')
                {
                    bool atDepositMenu = true;
                    while(atDepositMenu)
                    {
                        system("cls");
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "                [DEPOSIT CASH]                \n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << "   [A] Bangko ng Pilipinas (BNP)\n";
                        std::cout << "   [B] JCash\n";
                        std::cout << "   [C] Unavailable\n";
                        std::cout << "   [D] Unavailable\n";
                        std::cout << "   [O] Back\n";
                        std::cout << "+--------------------------------------------+\n";
                        std::cout << ": ";
                        char dChoice;
                        std::cin >> dChoice;
                        std::cout << std::endl;

                        if(dChoice == 'A' || dChoice == 'a')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Your Balance: PHP " << bnpBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Enter Deposit Amount: ";
                            double dAmount;
                            std::cin >> dAmount;
                            std::cout << std::endl;

                            bnpBalance += dAmount;
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   You deposited  : PHP " << dAmount << '\n';
                            std::cout << "   New Balance    : PHP " << bnpBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   [O] Back\n";
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << ": ";
                            char backChoice;
                            std::cin >> backChoice;
                            std::cout << std::endl;
                            atDepositMenu = false;
                        }
                        else if(dChoice == 'B' || dChoice == 'b')
                        {
                            system("cls");
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Your Balance: PHP " << jcashBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "Enter Deposit Amount: ";
                            double dAmount;
                            std::cin >> dAmount;
                            std::cout << std::endl;

                            jcashBalance += dAmount;
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   You deposited  : PHP " << dAmount << '\n';
                            std::cout << "   New Balance    : PHP " << jcashBalance << '\n';
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << "   [O] Back\n";
                            std::cout << "+--------------------------------------------+\n";
                            std::cout << ": ";
                            char backChoice;
                            std::cin >> backChoice;
                            std::cout << std::endl;
                            atDepositMenu = false;
                        }
                        else if(dChoice == 'C' || dChoice == 'c' || dChoice == 'D' || dChoice == 'd')
                        {
                            std::cout << "[!] This account slot is unavailable\n";
                            std::cout << "Press Enter to Retry\n";
                            std::cin.ignore();
                            std::cin.get();
                        }
                        else if(dChoice == 'O' || dChoice == 'o')
                            atDepositMenu = false;
                        else
                        {
                            std::cout << "[!] Invalid option\n";
                            std::cout << std::endl;
                        }
                    }
                }

                else if(transChoice == 'D' || transChoice == 'd')
                {
                    system("cls");
                    std::cout << "+--------------------------------------------+\n";
                    std::cout << "                 [CHANGE PIN]                 \n";
                    std::cout << "+--------------------------------------------+\n";

                    int currentPin;
                    std::cout << "   Enter Current PIN: ";
                    std::cin >> currentPin;
                    std::cout << std::endl;

                    while(currentPin != newPin)
                    {
                        std::cout << "[!] Incorrect current PIN. Try again.\n";
                        std::cout << std::endl;
                        std::cout << "   Enter Current PIN: ";
                        std::cin >> currentPin;
                        std::cout << std::endl;
                    }

                    int pin1, pin2;
                    std::cout << "   Enter New PIN: ";
                    std::cin >> pin1;
                    std::cout << "   Confirm New PIN: ";
                    std::cin >> pin2;
                    std::cout << std::endl;

                    while(pin1 != pin2)
                    {
                        std::cout << "[!] PINs do not match. Try again.\n";
                        std::cout << std::endl;
                        std::cout << "   Enter New PIN: ";
                        std::cin >> pin1;
                        std::cout << "   Confirm New PIN: ";
                        std::cin >> pin2;
                        std::cout << std::endl;
                    }

                    newPin = pin1;
                    std::cout << "+--------------------------------------------+\n";
                    std::cout << "         [OK] PIN changed successfully        \n";
                    std::cout << "+--------------------------------------------+\n";
                    std::cout << "Press Enter to Continue\n";
                    std::cin.ignore();
                    std::cin.get();
                    atTransMenu = false;
                    atMainMenu = false;
                }

                else if(transChoice == 'E' || transChoice == 'e')
                {
                    atTransMenu = false;
                    atMainMenu = false;
                }
                else
                {
                    std::cout << "[!] Invalid option\n";
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}
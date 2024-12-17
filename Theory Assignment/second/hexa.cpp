#include<iostream>
#include<random>

using namespace std;
random_device rd;
mt19937 generator(rd());
int main() {

     
     uniform_int_distribution<int> dist(0,65535);
    
    unsigned int random = dist(generator);
    cout<<random;
    
    string address = "0x0000";
    if(random == 0)
    {
        address = "0x0000";
    }
    int cnt = 5;
    int remainder;
    int hold;
    while(random != 0)
    {  
        hold = random;
         random = random / 16;
         remainder = hold - (random * 16);

        if(remainder > 9)
        {
            if(remainder == 10)
            {
                address[cnt] = 'A';
            }

            else if(remainder == 11)
            {
                address[cnt] = 'B';
            }

            else if(remainder == 12)
            {
                address[cnt] = 'C';
            }

            else if(remainder == 13)
            {
                address[cnt] = 'D';
            }

            else if(remainder == 14)
            {
                address[cnt] = 'E';
            }

             else //if(remainder == 15)
            {
                address[cnt] = 'F';
            }
           
        }
        else
        {  string store = to_string(remainder);
            address[cnt] = store[0];
        }
        cnt--;
    }
    cout<<endl;
    cout<<address;
    return 0;
}
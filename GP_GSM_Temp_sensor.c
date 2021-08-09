char str[70];
char *test="$GPGGA";
char logitude[10];
char latitude[10];
int i,j,k;
int temp;
int temppin =A2;
float temperature;

void setup() {
   Serial.begin(9600);   //Initialise serial to communicate with GSM Modem
    Serial.print("MEDICINE SUPPLIER"); 
    Serial.print("\nPackage Tracking System");
    delay(1000);

}

void loop() {
  delay(10000); //Give enough time for GSM to register on Network
     SendSMS();    //Send one SMS
     
     temperature =analogRead(temppin);
     temperature =temperature*(5000/1024);
     temperature = temperature/10;
     if (temp==1) 
  {
    for(i=18;i<27;i++)          //extract latitude from string
    {
     latitude[j]=str[i];
     j++;
    }
    for(i=30;i<40;i++)          //extract longitude from string
    {
    logitude[k]=str[i];
     k++;
    }
  }    
   }
    temp=0;
    i=0;
    j=0;
    k=0;
    delay(2000


void SendSMS()
{
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+917294903207\"\r"); //Change to destination phone number 
  delay(1000);
    Serial.print("Package Location ");
    Serial.print("Your Package Current Location is: ");
    Serial.print("https://www.google.com/maps/@");
    Serial.print(latitude);
    Serial.print(',');
    Serial.println(logitude);  
    Serial.print("Latitude(N): ");             //enter latitude in msg
    Serial.println(latitude);                  //enter latitude value in msg
    Serial.print("Longitude(E): ");            //enter Longitude in Msg
    Serial.println(logitude);                  //enter longitude value in msg
     
  delay(200);
  Serial.print("Temperature :");//the content of the message
  delay(200);
  Serial.print(temperature);//the content of the message
  delay(200);
   Serial.print("Degree Celsius");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);  
}
void serialEvent()
{
  while (Serial.available())            //Serial incomming data from GPS 
  {
    char inChar = (char)Serial.read(); 
    str[i]= inChar;                  //store incomming data from GPS to temparary string str[]
     i++;
     if (i < 7)                       
     {
      if(str[i-1] != test[i-1])         //check for right string
      {
        i=0; 
      }
     }
    if(i >=60)
    {
     temp=1;
    } 
  } 
}

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
//data dari firebase
#define FIREBASE_HOST "tugasakhir-a01a4.firebaseio.com"                         
#define FIREBASE_AUTH "SDP4Ppuwqqht2qmPmkxRJUdPohozYC3mnKWT94qj"                    
#define WIFI_SSID "andika"                                    
#define WIFI_PASSWORD "andika98"
//variable dari pin esp8266
#define Relay1 16
#define Relay2 5
#define Relay3 4
#define Relay4 0
#define Relay5 2 
#define Relay6 14
#define sensor 12
//variable untuk sensor 
int myString;
int sdata = 0;

void setup() {  
  Serial.begin(9600);  
  // connect to wifi  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print(".");  
    delay(500);  
  }  
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, INPUT);
  pinMode(12, OUTPUT);


  Firebase.set("Kamar_1",0);
  Firebase.set("Kipas",0);
  Firebase.set("Ruang_Tengah",0);
  Firebase.set("Kamar_2",0);
  Firebase.set("Kamar_Mandi",0);
  Firebase.set("Tandon_Air",0);
  Firebase.set("Alarm/Value",0);
 
}  
String n1, n2, n3, n4, n5, n6;

void loop() {
  n1=Firebase.getString("Kamar_1").toInt();; 
  n2=Firebase.getString("Kipas").toInt();; 
  n3=Firebase.getString("Ruang_Tengah").toInt();;
  n4=Firebase.getString("Kamar_2").toInt();; 
  n5=Firebase.getString("Kamar_Mandi").toInt();; 
  n6=Firebase.getString("Tandon_Air").toInt();; 

  sdata = digitalRead(sensor);
  myString = int(sdata); 
  Serial.println(myString); 
  Firebase.set("Alarm/Value",myString);
  
  long duration, distance;
  digitalWrite (13, LOW);
  delayMicroseconds (2);
  digitalWrite(13, HIGH);
  delayMicroseconds (10);
  digitalWrite(13, LOW);
  duration = pulseIn(15, HIGH);
  distance = (duration/2)/29.1;
  
  if (distance <=10)
  {
    digitalWrite(sensor, HIGH);
    delay (3000);           
  }
    
  else{
    digitalWrite(sensor, LOW);
  }
  
  if(n1=="1")                                                            
     {
      digitalWrite(Relay1,LOW);
      Serial.println("Relay 1 ON");
    }
  if(n1=="0")                                                      
    {                                      
      digitalWrite(Relay1,HIGH);
      Serial.println("Relay 1 OFF");
    }
  if(n2=="1")                                                             
     {
      digitalWrite(Relay2,LOW);
      Serial.println("Relay 2 ON");
    }
  if(n2=="0")                                                      
    {                                      
      digitalWrite(Relay2,HIGH);
      Serial.println("Relay 2 OFF");
    }
  if(n3=="1")                                                             
     {
      digitalWrite(Relay3,LOW);
      Serial.println("Relay 3 ON");
    }
  if(n3=="0")                                                      
    {                                      
      digitalWrite(Relay3,HIGH);
      Serial.println("Relay 3 OFF");
    }
  if(n4=="1")                                                            
     {
      digitalWrite(Relay4,LOW);
      Serial.println("Relay 4 ON");
    }
  if(n4=="0")                                                     
    {                                      
      digitalWrite(Relay4,HIGH);
      Serial.println("Relay 4 OFF");
    }
  if(n5=="1")                                                             
     {
      digitalWrite(Relay5,LOW);
      Serial.println("Relay 5 ON");
    }
  if(n5=="0")                                                      
    {                                      
      digitalWrite(Relay5,HIGH);
      Serial.println("Relay 5 OFF");
    }
  if(n6=="1")                                                           
     {
      digitalWrite(Relay6,LOW);
      Serial.println("Relay 6 ON");
    }
  if(n6=="0")                                                    
    {                                      
      digitalWrite(Relay6,HIGH);
      Serial.println("Relay 6 OFF");
    }
}

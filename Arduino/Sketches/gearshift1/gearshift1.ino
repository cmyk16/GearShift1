int ledPin = 13;   // LED connected to digital pin 13
int upPin = 7;     // pushbutton connected to digital pin 7
int downPin =6;

//ouputs
int upOut = 12;     // pushbutton connected to digital pin 7
int downOut =11;

int Inputvalup = 0;       // variable to store the read value
int Inputvaldown = 0;       // variable to store the read value

int uptime =1000;
int upcount =0;

int downtime =1000;
int downcount =0;

bool upReq =false;
bool downReq =false;



void setup()
{

  pinMode(upOut, OUTPUT);        // sets the digital pin 7 as input
  pinMode(downOut, OUTPUT);        // sets the digital pin 7 as input
  
  pinMode(upPin, INPUT);        // sets the digital pin 7 as input
  digitalWrite(upPin,HIGH);
  
  pinMode(downPin, INPUT);        // sets the digital pin 7 as input
  digitalWrite(downPin,HIGH);

  Serial.begin(57600);


}

void loop()
{
  Inputvalup = !digitalRead(upPin);     // read the input pin
  Inputvaldown = !digitalRead(downPin);     // read the input pin

  if(Inputvalup ==1){
    upReq =true;
  }

  if(Inputvaldown ==1){
    downReq =true;
  }

  if(upReq){
    if(upcount<uptime){
      digitalWrite(upOut, 1);    //open valve
      Serial.println("up 1 ");
    
    }else{

      digitalWrite(upOut, 0);    //open valve
      Serial.println("up 0 ");
      upReq =false;
      upcount=0;
    }
  upcount++;
    
  }

  if(downReq){
    if(downcount<downtime){
      digitalWrite(downOut, 1);    //open valve
      Serial.println("down 1");
    
    }else{

      digitalWrite(downOut, 0);    //open valve
      Serial.println("down 0");
      downReq =false;
      downcount=0;
    }
  downcount++;
    
  }
  
}


    const int trig = 8;    
    const int echo = 7;     
    int led = 6;
    void setup()
    {
        Serial.begin(9600);   
        pinMode(trig,OUTPUT);   
        pinMode(echo,INPUT);    
        pinMode(led,OUTPUT);
    }
     
    void loop()
    {
        unsigned long duration; 
        int distance;           
        
        /* Phát xung từ chân trig */
        digitalWrite(trig,0);   
        delayMicroseconds(2);
        digitalWrite(trig,1);  
        delayMicroseconds(5);   
        digitalWrite(trig,0);   
        
        /* Tính toán thời gian */
        // Đo độ rộng xung HIGH ở chân echo. 
        duration = pulseIn(echo,HIGH);  
        // Tính khoảng cách đến vật.
        distance = int(duration/2/29.412);
        
        /* In kết quả ra Serial Monitor */
        Serial.print(distance);
        Serial.println("cm");
        delay(200);
        if(distance<5){digitalWrite(led, HIGH);}else{digitalWrite(led, LOW);}
    }

//https://www.tinkercad.com/things/gj1P9k4Na9u?sharecode=OT7bgV1jrDuAOeFmiUYXAwnJJ-CyykULMH6EAkahIOI
//https://wokwi.com/projects/353735869255332865

// Classe LED
class LED {
  private:
  	int stato; //0 spento, 1 acceso
    int pin; // Pin del LED
    int i=0;
  	int n=10;

  public:
    // Costruttore: imposta la modalità del pin del LED come output
    LED(int p) {
      stato=0;
      pin = p;
      pinMode(pin, OUTPUT);
    }
  	
 void inverti()	//metodo inverti, se lo stato è 1 allora il led si spegne,se lo stato è 0 il LED si accende
  {
    if(stato==0)
      accendi();
    else
      spegni();
  }
  
  void lampeggio()	//metoro per il lampeggio del LED dopo ogni 500ms
  {
    for(i=0;i<n;i++)
    {
      delay(500);
      inverti();
      delay(500);
      inverti();
    }
  }
  
  void test()	//metodo per il test dei vari metodi
  {
    lampeggio();
  }

    // Metodo per accendere il LED
    void accendi() {
      digitalWrite(pin, HIGH);
      stato=1;
    }

    // Metodo per spegnere il LED
    void spegni() {
      digitalWrite(pin, LOW);
      stato=0;
    }
};

// Crea un oggetto LED sulla porta 13
LED led(11);

void setup() {
  // Non c'è nulla da fare qui
}

void loop() {
  // Accendi il LED
  //led.accendi();
  // Aspetta per un secondo
  //delay(1000);
  // Spegni il LED
  //led.spegni();
  // Aspetta per un secondo
  //delay(1000);
  led.lampeggio();
  delay(5000);	//pausa di 5 secondi tra un metodo e l'altro
  led.inverti();
  led.test();
}

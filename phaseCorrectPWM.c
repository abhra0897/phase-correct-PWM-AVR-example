void init_PWM()
{
    TCCR1A |= (1 << COM11) | (1 << WGM11); //non-inverting and mode 2
    TCCR1B |= (1 << CS11); //Prescaler 8 for desired 978Hz freq.
    DDRD |= (1 << PD5); //PWM o/p pin
    DDRD &= ~(1 <<< PB0);  //PB0 is i/p
    PORTB |= (1 << PB0); //enable internal pull-up
}

void update_OCR1A()
{
    if(!(PINB & (1 << PB0))) //if button is pressed
        OCR1A = 102;  //20% of TOP (511) as per mode 2
    else
        OCR1A = 434;  //85% of TOP
}

int main()
{
    update_OCR1A();
    init_PWM();
    while(1)
    {
        update_OCR1A();
    }
    return 0;
}

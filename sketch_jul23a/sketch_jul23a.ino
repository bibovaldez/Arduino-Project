int button1 = 0;
int button2 = 0;
int button3 = 0;
int button4 = 0;

int segmentdisplay1[7] = {0, 1, 2, 3, 4, 5, 6};
int segmentdisplay2[7] = {7, 8, 9, 10, 11, 12, 13};
int segmentnumbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displaynum(int second, int first)
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segmentdisplay1[i], segmentnumbers[first][i]);
        digitalWrite(segmentdisplay2[i], segmentnumbers[second][i]);
    };
}
void decoder(int p1, int p2, int p3, int p4)
{
    if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0)
    {
        displaynum(0, 0);
    }
    else if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 1)
    {
        displaynum(0, 1);
    }
    else if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 0)
    {
        displaynum(0, 2);
    }
    else if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 1)
    {
        displaynum(0, 3);
    }
    else if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 0)
    {
        displaynum(0, 4);
    }
    else if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 1)
    {
        displaynum(0, 5);
    }
    else if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 0)
    {
        displaynum(0, 6);
    }
    else if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 1)
    {
        displaynum(0, 7);
    }
    else if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 0)
    {
        displaynum(0, 8);
    }
    else if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1)
    {
        displaynum(0, 9);
    }
    else if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0)
    {
        displaynum(1, 0);
    }
    else if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 1)
    {
        displaynum(1, 1);
    }
    else if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0)
    {
        displaynum(1, 2);
    }
    else if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1)
    {
        displaynum(1, 3);
    }
    else if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 0)
    {
        displaynum(1, 4);
    }
    else if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1)
    {
        displaynum(1, 5);
    }
}

void setup()
{
    pinMode(A0, INPUT); // for 4 buttons
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);

    for (int i = 0; i < 7; i++)
    {
        pinMode(segmentdisplay1[i], OUTPUT);
        pinMode(segmentdisplay2[i], OUTPUT);
    };
}

void loop()
{
    button1 = digitalRead(A0);
    button2 = digitalRead(A1);
    button3 = digitalRead(A2);
    button4 = digitalRead(A3);
    decoder(button1, button2, button3, button4);
    displaynum();
}
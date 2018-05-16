package commeng1994412chenyangmeng_me433_2018.httpsgithub.helloworld;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    public static final int COUNTER = 2;            // "+" or "-" button increment with 2
    public static final int RESET = 50;             // "RESET" button to set the seekbar to 50
    SeekBar myControl;
    TextView myTextView;
    Button myPlusButton;
    Button myMinusButton;
    Button myResetButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myControl = (SeekBar) findViewById(R.id.seek1);                 // Initiate SeekBar

        myTextView = (TextView) findViewById(R.id.textView01);          // Initiate TextView
        myTextView.setText("Move the bar to update value or click the button to update / reset value");             // Set text

        myPlusButton = (Button) findViewById(R.id.button1);             // Initiate Button
        myMinusButton = (Button) findViewById(R.id.button2);
        myResetButton = (Button) findViewById(R.id.button3);


        setMyControlListener();
        setMyPlusButton();
        setMyMinusButton();
        setMyResetButton();

    }


    private void setMyControlListener() {
        // function to detect when slider is used

        myControl.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {

            int progressChanged = 0;

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                progressChanged = progress;
                myTextView.setText("The value is: " + progress);          // Display the text
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    private void setMyPlusButton() {
        // funtion to detect when the "+" button is used

        myPlusButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myControl.setProgress(myControl.getProgress() + COUNTER);
            }
        });
    }


    private void setMyMinusButton() {
        // function to detect when the "-" button is used

        myMinusButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myControl.setProgress(myControl.getProgress() - COUNTER);
            }
        });
    }

    private void setMyResetButton() {
        // function to detect when the "RESET" button is used

        myResetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myControl.setProgress(RESET);
            }
        });
    }

}
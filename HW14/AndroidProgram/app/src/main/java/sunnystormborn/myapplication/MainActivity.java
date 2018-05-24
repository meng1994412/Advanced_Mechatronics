package sunnystormborn.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;
import android.widget.Button;


public class MainActivity extends AppCompatActivity {

    SeekBar myControl;
    TextView myTextView;

    // new widgets for hw4
    Button button;
    TextView myTextView2;
    ScrollView myScrollView;
    TextView myTextView3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myControl = (SeekBar) findViewById(R.id.seek1);                 // initiate SeekBar

        myTextView = (TextView) findViewById(R.id.textView01);          // initiate TextView
        myTextView.setText("Move the bar to update value");             // set text

        // detect when the button is pressed that writes the slider position to the textview
        myTextView2 = (TextView) findViewById(R.id.textView02);         // initiate TextView2
        myScrollView = (ScrollView) findViewById(R.id.ScrollView01);    // initiate ScrollView
        myTextView3 = (TextView) findViewById(R.id.textView03);         // initiate TextView3
        button = (Button) findViewById(R.id.button1);                   // initiate button

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myTextView2.setText("value on click is " + myControl.getProgress());
            }
        });

        setMyControlListener();
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
}

package com.example.legendkiller.myapplication;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Patterns;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Scroller;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {

    EditText name,phon,email;
    Spinner city;
    Button btn;
    String []data = {"","Delhi","Mumbai","Kolkata","Chennai","Banglore"};
    String val1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        name=(EditText)findViewById(R.id.editText);
        phon=(EditText)findViewById(R.id.editText2);
        email=(EditText)findViewById(R.id.editText3);
        city=(Spinner) findViewById(R.id.spinner);
        btn=(Button)findViewById(R.id.button);

        ArrayAdapter ad = new ArrayAdapter(this,android.R.layout.simple_dropdown_item_1line,data);
        ad.setDropDownViewResource(android.R.layout.simple_dropdown_item_1line);
        city.setAdapter(ad);
        city.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int i, long id) {
                val1 = data[i];
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String Name = name.getText().toString();
                String Phon = phon.getText().toString();
                String Email = email.getText().toString();

                if(!Patterns.EMAIL_ADDRESS.matcher(Email).matches()) {  //check email is correctly entered or not
                    email.setError("Please Enter A Valid Email");
                    email.requestFocus();
                    return;
                }

                if(Name.length()==0){
                    name.setBackgroundColor(Color.RED);
                }
                else
                {
                    name.setBackgroundColor(Color.WHITE);
                }

                if(Phon.length()==0){
                    phon.setBackgroundColor(Color.RED);
                }
                else
                {
                    phon.setBackgroundColor(Color.WHITE);
                }

                if(Email.length()==0){
                    email.setBackgroundColor(Color.RED);
                }
                else
                {
                    email.setBackgroundColor(Color.WHITE);
                }

                if(val1.length()==0){
                    city.setBackgroundColor(Color.RED);
                }
                else
                {
                    city.setBackgroundColor(Color.WHITE);
                }


            }
        });
    }
}

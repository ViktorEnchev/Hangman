package com.example.game.hangman;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import org.json.JSONObject;

import java.net.URL;

public class RegisterActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        Button loginButton = (Button) findViewById(R.id.btnLogin2);
        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(RegisterActivity.this, LoginActivity.class));
            }
        });

        Button regButton = (Button) findViewById(R.id.btnRegister2);
        final EditText username = (EditText) findViewById(R.id.regUsername);
        final EditText password = (EditText) findViewById(R.id.regPassword);
        regButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                JSONObject urlParameters = new JSONObject();
                try {
                    URL url = new URL("http://10.0.2.2:8080/hangman/register");
                    urlParameters.put("username", username.getText().toString());
                    urlParameters.put("password", password.getText().toString());
                    NetworkHandler networkHandler = new NetworkHandler(urlParameters, url);
                    Object[] ObjectTmp = new Object[1];
                    AsyncTask taskResult = networkHandler.execute(ObjectTmp);
                    Object result = taskResult.get();
                } catch (Exception e) {
                    e.printStackTrace();
                }

                startActivity(new Intent(RegisterActivity.this, LobbyActivity.class));
            }
        });
    }

}

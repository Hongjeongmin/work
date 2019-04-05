package org.techtown.activity_transform;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;
import android.os.Bundle;

public class SubActivity extends AppCompatActivity {
    @Override
    protected  void onCreate(Bundle bundle){
        super.onCreate(bundle);
        setContentView(R.layout.activity_sub);
        TextView nameText = (TextView) findViewById(R.id.nameText);
        Intent intent = getIntent();
        nameText.setText(intent.getStringExtra("nameText").toString());
    }
}

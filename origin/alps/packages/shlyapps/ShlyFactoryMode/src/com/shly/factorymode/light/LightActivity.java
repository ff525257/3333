package com.shly.factorymode.light;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Intent;
import android.os.Bundle;
import android.provider.Settings;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Switch;

import com.shly.factorymode.FactoryMode;
import com.shly.factorymode.R;
import com.shly.factorymode.backlight.BackLight;

public class LightActivity extends Activity {
    private final int LIGHT_ID = 0x27;
	private Notification.Builder builder;
    private NotificationManager manager;
    private Button succesButton;
    private Button failButton;
    private int mNotificationSettingValue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        setContentView(R.layout.light);
        //Button mRedButton = (Button) findViewById(R.id.Light_red);
        Button mBlueButton = (Button) findViewById(R.id.Light_blue);
        //mRedButton.setOnTouchListener(mTouchListener);
        mBlueButton.setOnTouchListener(mTouchListener);
        manager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
		
		builder = new Notification.Builder(this);
		builder.setContentInfo("");
		builder.setContentText("");
		builder.setContentTitle("");
		builder.setSmallIcon(R.drawable.ic_launcher);
		builder.setTicker("");
		builder.setAutoCancel(true);
		builder.setPriority(Notification.PRIORITY_MAX);
		builder.setWhen(System.currentTimeMillis());
		int defaults = 0;
		defaults |= Notification.FLAG_SHOW_LIGHTS;
		defaults |= Notification.FLAG_AUTO_CANCEL;
		builder.setDefaults(defaults);
		builder.setSound(null);
		
        this.succesButton = ((Button) findViewById(R.id.display_bt_ok));
        this.failButton = ((Button) findViewById(R.id.display_bt_failed));
        this.succesButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View paramView) {
                Intent localIntent = new Intent(LightActivity.this,
                        FactoryMode.class);
                setResult(-1, localIntent);
                finish();
            }
        });
        this.failButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View paramView) {
                Intent localIntent = new Intent(LightActivity.this,
                        FactoryMode.class);
                setResult(0, localIntent);
                finish();
            }
        });
    }

    View.OnTouchListener mTouchListener = new View.OnTouchListener() {

        @Override
        public boolean onTouch(View arg0, MotionEvent arg1) {
            switch (arg1.getAction()) {
            case MotionEvent.ACTION_DOWN:
                turnOnLight(arg0.getId());
                break;
            case MotionEvent.ACTION_UP:
                turnOffLight();
                break;

            default:
                break;
            }
            return false;
        }
    };

    private void turnOnLight(int resId) {
        int color = 0xffff0000;//getResources().getColor(R.color.Red);
        builder.setLights(color, 500, 2000);	
        manager.notify(LIGHT_ID, builder.build());
    }

    private void turnOffLight() {
        manager.cancel(LIGHT_ID);
    }

    @Override
    protected void onResume() {
        super.onResume();
        Settings.System.putInt(getContentResolver(),
                Settings.System.LIGHTS_NOTIFICATION_FACTORYMODE, 1);
    }

    @Override
    protected void onStop() {
        super.onStop();
        Settings.System.putInt(getContentResolver(),
                Settings.System.LIGHTS_NOTIFICATION_FACTORYMODE, 0);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Settings.System.putInt(getContentResolver(),
                Settings.System.LIGHTS_NOTIFICATION_FACTORYMODE, 0);
    }
}


package com.shly.factorymode;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.GridView;
import android.widget.SimpleAdapter;
import java.util.ArrayList;
import java.util.HashMap;
import android.util.LyFeatureUtils;
import com.shly.factorymode.R;

public class KeyCode extends Activity
{
  public static final int KEY_BACK = 2;
  public static final int KEY_CAMERA = 6;
  public static final int KEY_HOME = 1;
  public static final int KEY_MAX = 7;
  public static final int KEY_MENU = 0;
  public static final int KEY_SEARCH = 3;
  public static final int KEY_START = 0;
  public static final int KEY_VOLUME_DOWN = 4;
  public static final int KEY_VOLUME_UP = 5;
  private static final boolean bkeyback = true;
  private static final boolean bkeycamera = false;
  private static final boolean bkeyhome = true;
  private static final boolean bkeymenu = true;
  private static final boolean bkeysearch = false;
  private static final boolean bkeyvld = true;
  private static final boolean bkeyvlu = true;
  Button failButton;
  private GridView gridview;
  private boolean keybacktested = false;
  private boolean keycameratested = false;
  private boolean keyhometested = false;
  private boolean keymenutested = false;
  private boolean keysearchtested = false;
  private boolean keyvldtested = false;
  private boolean keyvlutested = false;
  ArrayList<HashMap<String, Object>> lstImageItem;
  HashMap<String, Object> map;
  SimpleAdapter saImageItems;
  Button succesButton;

  public void onAttachedToWindow()
  {
    super.onAttachedToWindow();
    getWindow().addFlags(-2147483648);
  }

  protected void onCreate(Bundle paramBundle)
  {
    super.onCreate(paramBundle);
    setContentView(R.layout.keycode);
    this.gridview = ((GridView)findViewById(R.id.keycode_grid));
    this.lstImageItem = new ArrayList();
    ArrayList localArrayList = this.lstImageItem;
    String[] arrayOfString = new String[1];
    arrayOfString[0] = "imageView";
    int[] arrayOfInt = new int[1];
    arrayOfInt[0] = R.id.imgview;
    this.saImageItems = new SimpleAdapter(this, localArrayList, R.layout.keycode_grid, arrayOfString, arrayOfInt);
    this.succesButton = ((Button)findViewById(R.id.keycode_bt_ok));
    this.failButton = ((Button)findViewById(R.id.keycode_bt_failed));
    this.succesButton.setEnabled(false);
    this.map = new HashMap();
    boolean hasNavigationBar = LyFeatureUtils.LYCONFIG_FEA_NAVIGATION_BAR_SUPPORT;
    Log.d("wanggang", "hasNavigationBar: "+hasNavigationBar);
    if(!hasNavigationBar) {
        this.map.put("imageView", Integer.valueOf(R.drawable.menu));
        this.lstImageItem.add(this.map);
        this.gridview.setAdapter(this.saImageItems);
        this.map = new HashMap();
        this.map.put("imageView", Integer.valueOf(R.drawable.home));
        this.lstImageItem.add(this.map);
        this.gridview.setAdapter(this.saImageItems);
        this.map = new HashMap();
        this.map.put("imageView", Integer.valueOf(R.drawable.back));
        this.lstImageItem.add(this.map);
        this.gridview.setAdapter(this.saImageItems);
        this.map = new HashMap();
    }
    if(LyFeatureUtils.LYCONFIG_FEA_HAS_CAMERA_KEY) {
        this.map.put("imageView", Integer.valueOf(R.drawable.camera));
        this.lstImageItem.add(this.map);
        this.gridview.setAdapter(this.saImageItems);
        this.map = new HashMap();
    }
	if(LyFeatureUtils.LYCONFIG_FEA_HAS_SOS_KEY) {
        this.map.put("imageView", Integer.valueOf(R.drawable.sos));
        this.lstImageItem.add(this.map);
        this.gridview.setAdapter(this.saImageItems);
        this.map = new HashMap();
    }

    this.map.put("imageView", Integer.valueOf(R.drawable.vldown));
    this.lstImageItem.add(this.map);
    this.gridview.setAdapter(this.saImageItems);
    this.map = new HashMap();
    this.map.put("imageView", Integer.valueOf(R.drawable.vlup));
    this.lstImageItem.add(this.map);
    this.gridview.setAdapter(this.saImageItems);
    this.succesButton.setOnClickListener(new View.OnClickListener()
    {
      public void onClick(View paramView)
      {
        Intent localIntent = new Intent(KeyCode.this, FactoryMode.class);
        KeyCode.this.setResult(-1, localIntent);
        KeyCode.this.finish();
      }
    });
    this.failButton.setOnClickListener(new View.OnClickListener()
    {
      public void onClick(View paramView)
      {
        Intent localIntent = new Intent(KeyCode.this, FactoryMode.class);
        KeyCode.this.setResult(0, localIntent);
        KeyCode.this.finish();
      }
    });
  }

  public boolean onKeyDown(int paramInt, KeyEvent paramKeyEvent)
  {
    boolean i = true;
    this.map = new HashMap();
    switch(paramInt){
	    case KeyEvent.KEYCODE_MENU://menu
	    	 if (!this.keymenutested){
		         this.map.put("imageView", Integer.valueOf(R.drawable.menu));
		         this.lstImageItem.remove(this.map);
		         this.keymenutested = i;
	    	 }
	    	 break;
	    case KeyEvent.KEYCODE_HOME://home 
	    	 if (!this.keyhometested){
		         this.map.put("imageView", Integer.valueOf(R.drawable.home));
		         this.lstImageItem.remove(this.map);
		         this.keyhometested = i;
	    	 }
	    	 break;
	    case KeyEvent.KEYCODE_BACK://back
	    	 if (!this.keybacktested){
		         this.map.put("imageView", Integer.valueOf(R.drawable.back));
		         this.lstImageItem.remove(this.map);
		         this.keybacktested = i;
	    	 }
	    	 break;
	    case 84:
	    	 if (!this.keysearchtested){
	         this.map.put("imageView", Integer.valueOf(R.drawable.search));
	         this.lstImageItem.remove(this.map);
	         this.keysearchtested = i;
	    	 }
	    	 break;
	    case KeyEvent.KEYCODE_VOLUME_DOWN:
	    	if (!this.keyvldtested){
	        this.map.put("imageView", Integer.valueOf(R.drawable.vldown));
	        this.lstImageItem.remove(this.map);
	        this.keyvldtested = i;
	    	}
	    	break;
	    case KeyEvent.KEYCODE_VOLUME_UP:
	    	  if (!this.keyvlutested){
		          this.map.put("imageView", Integer.valueOf(R.drawable.vlup));
		          this.lstImageItem.remove(this.map);
		          this.keyvlutested = i;
	    	  }
	    	  break;
	    case 27:
	    	   if (!this.keycameratested){
	    	      this.map.put("imageView", Integer.valueOf(R.drawable.camera));
	    	      this.lstImageItem.remove(this.map);
	    	      this.keycameratested = i;
	    	   }
	    	   break;
		 case 45:
	    	   if (!this.keycameratested){
	    	      this.map.put("imageView", Integer.valueOf(R.drawable.sos));
	    	      this.lstImageItem.remove(this.map);
	    	      this.keycameratested = i;
	    	   }
	    	   break;
	    default:
	        break;
    }
     
      this.gridview.setAdapter(this.saImageItems);
      if (this.lstImageItem.size() > 0){
      }else{
      this.succesButton.setEnabled(i);
      }
     /* if ((FactoryMode.getCurrentTestMode() != 2) && (FactoryMode.getCurrentTestMode() != i))
        continue;
      setResult(-1, new Intent(this, FactoryMode.class));*/
      return i;
  }
/*
  public boolean onKeyUp(int paramInt, KeyEvent paramKeyEvent)
  {
    switch (paramInt)
    {
    default:
    case 3:
    case 4:
    case 24:
    case 25:
    case 27:
    case 82:
    case 84:
    }
    for (boolean bool = super.onKeyUp(paramInt, paramKeyEvent); ; bool = true)
      return bool;
  }*/
}

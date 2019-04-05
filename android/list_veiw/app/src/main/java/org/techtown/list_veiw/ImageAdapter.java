package org.techtown.list_veiw;

import android.content.Context;
import android.provider.ContactsContract;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class ImageAdapter extends ArrayAdapter<String> {

    ImageAdapter(Context context, String[] items){
        super(context, R.layout.image_layout,items);

    }

    //@androidx.annotation.NonNull
    @NonNull
    @Override
    public View getView(int position,View convertView, ViewGroup parent) {
        LayoutInflater imageInflater = LayoutInflater.from(getContext());
        View view = imageInflater.inflate(R.layout.image_layout,parent,false);
        String item = getItem(position);
        TextView textView = (TextView) view.findViewById(R.id.textView);
        ImageView imageView = (ImageView) view.findViewById(R.id.imageView);
        textView.setText(item);
        if(position == 1){
            imageView.setImageResource(R.mipmap.iu);
        }
        else if(position == 2){
            imageView.setImageResource(R.mipmap.su);
        }
        else{
            imageView.setImageResource(R.mipmap.ye);
        }

        return  view;
    }
}

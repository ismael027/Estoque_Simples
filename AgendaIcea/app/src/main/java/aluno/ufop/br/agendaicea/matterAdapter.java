package aluno.ufop.br.agendaicea;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class matterAdapter extends BaseAdapter {

    private ArrayList<Materias> list;
    private Context context;

    public matterAdapter(ArrayList<Materias> list, Context context) {
        this.list = list;
        this.context = context;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public Object getItem(int position) {
        return list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        Materias materias = list.get(position);
        LayoutInflater inflater = (LayoutInflater)
                context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View v = inflater.inflate(
                R.layout.activity_matter_adapter,
                null);

        //Atualiza os componentes com os dados do estudante
        TextView tvNome = v.findViewById(R.id.nameMatter);

        tvNome.setText("" + materias.getNome() + " - ");
        tvNome.setText(materias.getNome());


        return v;

    }
}

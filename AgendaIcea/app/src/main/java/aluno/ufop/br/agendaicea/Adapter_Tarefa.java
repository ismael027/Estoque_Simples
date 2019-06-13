package aluno.ufop.br.agendaicea;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class Adapter_Tarefa extends BaseAdapter {

    private ArrayList<Tarefa> list;
    private Context context;

    public Adapter_Tarefa(ArrayList<Tarefa> list, Context context) {
        this.list = list;
        this.context = context;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public Object getItem(int i) {
        return list.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        Tarefa tar = list.get(i);
        LayoutInflater inflater = (LayoutInflater)
                context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View v = inflater.inflate(R.layout.adapter_tarefa, null);

        TextView tnome = v.findViewById(R.id.nome);
        TextView tdisciplina = v.findViewById(R.id.disciplina);
        TextView tdata = v.findViewById(R.id.data);
        TextView tvalor = v.findViewById(R.id.valor);

        tnome.setText(tar.getNome());
        tdisciplina.setText(tar.getDisciplina());
        tdata.setText(tar.getData());
        tvalor.setText(""+tar.getValor());


        return v;
    }
}

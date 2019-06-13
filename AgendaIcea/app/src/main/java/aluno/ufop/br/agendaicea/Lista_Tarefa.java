package aluno.ufop.br.agendaicea;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

public class Lista_Tarefa extends AppCompatActivity {
    private ListView lvTarefa;
    private TextView tvEmptyList;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lista__tarefa);
        lvTarefa =
                (ListView) findViewById(R.id.listTarefa);
        tvEmptyList =
                (TextView) findViewById(R.id.tvEmptyList);

    }

    @Override
    protected void onResume() {
        super.onResume();
        if(SharedResourceT.getInstance().getTarefas().isEmpty()){
            tvEmptyList.setVisibility(View.VISIBLE);
        } else {
            tvEmptyList.setVisibility(View.INVISIBLE);
        }
        lvTarefa.setAdapter(new Adapter_Tarefa(SharedResourceT.getInstance().getTarefas(),this));
        lvTarefa.setOnItemClickListener( new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                Intent it = new Intent(
                        Lista_Tarefa.this,
                        Edit_Tarefa.class);
                it.putExtra("position", position);
                startActivity(it);
            }
        });
        }

        public void addTarefa(View view){
        Intent it = new Intent(this,add_terefa.class);
        startActivity(it);
        }

}

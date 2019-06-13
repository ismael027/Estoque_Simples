package aluno.ufop.br.agendaicea;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;

public class mainActivity extends AppCompatActivity  {
    private ListView lvMatters;
    private TextView tvEmptyList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        lvMatters =
                (ListView) findViewById(R.id.listMatters);
        tvEmptyList =
                (TextView) findViewById(R.id.tvEmptyList);
        SharedResources.getInstance().loadMatter(this);
        SharedResourceT.getInstance().loadTarefa(this);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(SharedResources.getInstance().getMatter().isEmpty()) {
            tvEmptyList.setVisibility(View.VISIBLE);
        } else {
            tvEmptyList.setVisibility(View.INVISIBLE);
        }
        lvMatters.setAdapter(new     matterAdapter(SharedResources.getInstance().getMatter(),   this));
        lvMatters.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                //Exibir intent para cadastrar tarefa

                Intent it = new Intent(
                        mainActivity.this,
                        editMatter.class);
                it.putExtra("position", position);
                startActivity(it);
            }
        });

        lvMatters.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                Intent it = new Intent(
                        mainActivity.this,
                        editMatter.class);
                it.putExtra("position", position);
                startActivity(it);
                return true;
            }
        });
    }

    public void addMatters(View view) {
        Intent it = new Intent(
                this, addMatter.class);
        startActivity(it);
    }

    public void ver(View view){
        Intent it = new Intent(this,Lista_Tarefa.class);
        startActivity(it);
    }


}

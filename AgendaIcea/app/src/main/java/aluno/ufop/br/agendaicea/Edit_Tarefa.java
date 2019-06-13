package aluno.ufop.br.agendaicea;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class Edit_Tarefa extends AppCompatActivity {
    private EditText et_nome;
    private EditText et_disciplina;
    private EditText et_data;
    private EditText et_valor;
    int position;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit__tarefa);
        et_nome = findViewById(R.id.nome_tarefa);
        et_disciplina = findViewById(R.id.ed_disciplina);
        et_data =  findViewById(R.id.ed_dataentrega);
        et_valor = findViewById(R.id.et_valor);

        Intent it = getIntent();
        position = it.getIntExtra("position", 0);

        et_nome.setText(SharedResourceT.getInstance().getTarefas().get(position).getNome());
        et_disciplina.setText(SharedResourceT.getInstance().getTarefas().get(position).getDisciplina());
        et_data.setText(SharedResourceT.getInstance().getTarefas().get(position).getData());
        et_valor.setText(String.valueOf(SharedResourceT.getInstance().getTarefas().get(position).getValor()));

    }

    public void add(View view){
        String nome = et_nome.getText().toString();
        String disciplina = et_disciplina.getText().toString();
        String data= et_data.getText().toString();
        int valor = Integer.parseInt(et_valor.getText().toString());
        SharedResourceT.getInstance().getTarefas().remove(position);

        Tarefa tar = new Tarefa(nome, disciplina, data, valor);

        SharedResourceT.getInstance().getTarefas().add(tar);
        SharedResourceT.getInstance().saveTarefa(this);
        Toast.makeText(this, "Tarefa editada com sucesso!",
                Toast.LENGTH_SHORT).show();
        finish();

    }

    public void Delete(View view){
        SharedResourceT.getInstance().getTarefas().remove(position);
        SharedResourceT.getInstance().saveTarefa(this);
        Toast.makeText(this, "Tarefa removida com sucesso!", Toast.LENGTH_SHORT).show();
        finish();
    }
}

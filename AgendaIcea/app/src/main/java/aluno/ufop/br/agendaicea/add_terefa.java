package aluno.ufop.br.agendaicea;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class add_terefa extends AppCompatActivity {

    private EditText et_nome;
    private EditText et_disciplina;
    private EditText et_data;
    private EditText et_valor;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_terefa);
        et_nome = findViewById(R.id.nome_tarefa);
        et_disciplina = findViewById(R.id.ed_disciplina);
        et_data =  findViewById(R.id.ed_dataentrega);
        et_valor = findViewById(R.id.et_valor);

    }

    public void add(View view){
        String nome = et_nome.getText().toString();
        String disciplina = et_disciplina.getText().toString();
        String data= et_data.getText().toString();
        int valor = Integer.parseInt(et_valor.getText().toString());

        Tarefa tar = new Tarefa(nome, disciplina, data, valor);

        SharedResourceT.getInstance().getTarefas().add(tar);
        Toast.makeText(this, "Tarefa registrada com sucesso!",
                Toast.LENGTH_SHORT).show();
        finish();
    }
}

package aluno.ufop.br.agendaicea;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.Toast;



public class addMatter extends AppCompatActivity {




    private EditText etNome;
    private EditText etSemestre;
    private EditText etFaltas;
    private EditText etLimite;
    private EditText etMeta;
    private Switch swStatus;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etNome =  findViewById(R.id.etNome);
        etSemestre =  findViewById(R.id.etSemestre);
        etFaltas =  findViewById(R.id.etFaltas);
        etLimite =  findViewById(R.id.etLimite);
        etMeta =  findViewById(R.id.etMeta);
        swStatus = findViewById(R.id.swStatus);
    }

    public void cadMatter(View view) {

        String nome = etNome.getText().toString();
        int Semestre = Integer.parseInt(etSemestre.getText().toString());
        int Faltas = Integer.parseInt(etFaltas.getText().toString());
        int Limite = Integer.parseInt(etLimite.getText().toString());
        double Meta = Double.parseDouble(etMeta.getText().toString());
        boolean status;
        if (swStatus.isChecked())
            status = true;
        else
            status = false;

        Materias materia = new Materias(nome,Semestre,Faltas,Limite,Meta,status);
        SharedResources.getInstance().
                getMatter().add(materia);
        SharedResources.getInstance().saveMatter(this);

        Toast.makeText(this, "Matéria registrada com sucesso!",
                Toast.LENGTH_SHORT).show();

        etNome.setText("");
        etSemestre.setText("");
        etFaltas.setText("");
        etLimite.setText("");
        etMeta.setText("");
        swStatus.setChecked(false);

    }

}
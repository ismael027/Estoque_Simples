package aluno.ufop.br.agendaicea;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.Toast;

public class editMatter extends AppCompatActivity {

    private EditText etNome;
    private EditText etSemestre;
    private EditText etFaltas;
    private EditText etLimite;
    private EditText etMeta;
    private Switch swStatus;
    private int position;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_matter);
        etNome =  findViewById(R.id.etNome);
        etSemestre =  findViewById(R.id.etSemestre);
        etFaltas =  findViewById(R.id.etFaltas);
        etLimite =  findViewById(R.id.etLimite);
        etMeta =  findViewById(R.id.etMeta);
        swStatus = findViewById(R.id.swStatus);

        Intent it = getIntent();
        position = it.getIntExtra("position", 0);

        //Load matter info into text fields

        etNome.setText(SharedResources.getInstance().getMatter().get(position).getNome());
        etSemestre.setText(String.valueOf(SharedResources.getInstance().getMatter().get(position).getSem()));
        etFaltas.setText(String.valueOf(SharedResources.getInstance().getMatter().get(position).getFalt()));
        etLimite.setText(String.valueOf(SharedResources.getInstance().getMatter().get(position).getLim()));
        etMeta.setText(String.valueOf(SharedResources.getInstance().getMatter().get(position).getMeta()));
        if (SharedResources.getInstance().getMatter().get(position).getStatus() == true)
        {
            swStatus.setChecked(true);
        }
        else {
            swStatus.setChecked(false);
        }
    }

    public void confirm(View view) {
        String nome = etNome.getText().toString();
        int semestre = Integer.parseInt(etSemestre.getText().toString());
        int faltas = Integer.parseInt(etFaltas.getText().toString());
        int limite = Integer.parseInt(etLimite.getText().toString());
        double meta = Double.parseDouble(etMeta.getText().toString());
        boolean status;
        if (swStatus.isChecked())
            status = true;
        else
            status = false;

        Materias materias = new Materias(nome,semestre,faltas,limite,meta,status);
        SharedResources.getInstance().getMatter().add(materias);
        SharedResources.getInstance().saveMatter(this);
        Toast.makeText(this, "Matéria editada com sucesso!", Toast.LENGTH_SHORT).show();
        finish();
    }

    public void delete(View view) {
        SharedResources.getInstance().getMatter().remove(position);
        SharedResources.getInstance().saveMatter(this);
        Toast.makeText(this, "Matéria removida com sucesso!", Toast.LENGTH_SHORT).show();
        finish();
    }
}

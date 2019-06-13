package aluno.ufop.br.agendaicea;

import android.content.Context;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class SharedResourceT {
    public static SharedResourceT shared
            = null;

    //Singleton elements
    private static ArrayList<Tarefa>
           tarefas;

    public static SharedResourceT getInstance() {
        if(shared == null) {
            shared = new SharedResourceT();
        }
        return shared;
    }

    private SharedResourceT() {
        tarefas = new ArrayList<>();
    }

    public ArrayList<Tarefa> getTarefas() {
        return tarefas;
    }

    public void loadTarefa(Context context) {
        try {
            FileInputStream fis = context.openFileInput("tarefa.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
            tarefas = (ArrayList<Tarefa>)ois.readObject();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void saveTarefa(Context context)
    {
        try {
            FileOutputStream fos = context.openFileOutput("tarefa.dat",Context.MODE_PRIVATE);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(tarefas);
            oos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

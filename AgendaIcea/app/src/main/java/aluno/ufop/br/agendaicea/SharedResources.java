package aluno.ufop.br.agendaicea;

import android.content.Context;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class SharedResources {

    public static SharedResources shared
            = null;

    //Singleton elements
    private static ArrayList<Materias>
            matter;

    public static SharedResources getInstance() {
        if(shared == null) {
            shared = new SharedResources();
        }
        return shared;
    }

    private SharedResources() {
        matter = new ArrayList<>();
    }

    public ArrayList<Materias> getMatter() {
        return matter;
    }

    public void loadMatter(Context context) {
        try {
            FileInputStream fis = context.openFileInput("matter.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
            matter = (ArrayList<Materias>)ois.readObject();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void saveMatter(Context context)
    {
        try {
            FileOutputStream fos = context.openFileOutput("matter.dat",Context.MODE_PRIVATE);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(matter);
            oos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

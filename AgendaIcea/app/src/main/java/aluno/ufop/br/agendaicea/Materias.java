package aluno.ufop.br.agendaicea;

import java.io.Serializable;

public class Materias implements Serializable{

    private String nome;
    private int sem;
    private int falt;
    private int lim;
    private double meta;
    private boolean status;

    public Materias( String nome, int sem, int falt, int lim, double meta, boolean status) {

        this.nome = nome;
        this.sem = sem;
        this.falt = falt;
        this.lim = lim;
        this.meta = meta;
        this.status = status;
    }


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getSem() {
        return sem;
    }

    public void setSem(int sem) {
        this.sem = sem;
    }

    public int getFalt() {
        return falt;
    }

    public void setFalt(int falt) {
        this.falt = falt;
    }

    public int getLim() {
        return lim;
    }

    public void setLim(int lim) {
        this.lim = lim;
    }

    public double getMeta() {
        return meta;
    }

    public void setMeta(double meta) {
        this.meta = meta;
    }

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Materias{" +

                ", nome='" + nome + '\'' +
                ", sem=" + sem +
                ", falt=" + falt +
                ", lim=" + lim +
                ", meta=" + meta +
                ", status='" + status + '\'' +
                '}';
    }
}

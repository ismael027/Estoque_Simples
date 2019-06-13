package aluno.ufop.br.agendaicea;

public class Tarefa {

    private String nome;
    private String Disciplina;
    private String data;
    private int valor;

    public Tarefa(String nome, String disciplina, String data, int valor) {
        this.nome = nome;
        Disciplina = disciplina;
        this.data = data;
        this.valor = valor;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDisciplina() {
        return Disciplina;
    }

    public void setDisciplina(String disciplina) {
        Disciplina = disciplina;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public int getValor() {
        return valor;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }
}

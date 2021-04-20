import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Lab2and3 {
    import java.util.ArrayList;
import java.util.Stack;
    

public class Edge {

    public int weight;
    public Vertex from,to;
    public Edge(Vertex From,Vertex To) {

        from=From;
        to=To;
        weight=1;
    }
}
public class Vertex {

    public int number;

    public Vertex(int Number) {
        number = Number;
    }
}

public class Graph {

    ArrayList<Vertex> Vertexes=new ArrayList<>();

    ArrayList<Edge> Edges=new ArrayList<>();

    public void addVertex(Vertex vertex){

        Vertexes.add(vertex);
    }

    public void addEdge(Vertex From,Vertex To){

        Edge edge=new Edge(From,To);

        Edges.add(edge);
    }

    public int[][] getMatrix() {

        int s= Vertexes.size();
        int[][] matrix=new int[s][s];

        for(Edge E:Edges){

            int row=E.from.number-1;
            int column=E.to.number-1;

            matrix[row][column]=E.weight;
        }
        return matrix;
    }
    public Vertex vertexSearch(int number){

        for(Vertex v:Vertexes){

            if(v.number==number)return v;
        }

        return null;
    }
    public ArrayList<Vertex> getVertexList(Vertex vertex){
        ArrayList<Vertex> result=new ArrayList<>();
        for(Edge E:Edges){
            if(E.from==vertex){
                result.add(E.to);
            }
        }
        return result;
    }
    public void smeMatrix(){
        int m[][]=getMatrix(),I=Vertexes.size();

        for(int i=0;i<I;++i){
            for(int j=0;j<I;++j){

                System.out.print(m[i][j]);
            }
            System.out.println();
        }
    }
    public void smeList(){
        int i=1;
        for(Vertex V:Vertexes){
            ArrayList<Vertex> out=getVertexList(V);
            System.out.print(i+" - ");
            for(Vertex v:out){
                System.out.print(v.number+",");
            }
            System.out.println("0;");
            ++i;
        }
    }
    public boolean containEdge(Vertex from, Vertex to){
        for(Edge e:Edges){
            if(e.from==from&&e.to==to){
                return true;
            }
        }
        return false;
    }
    public boolean dfs(Vertex start,Vertex finish){
        if(start==null||finish==null)return false;
        else if(start==finish)return true;
        Stack<Vertex> stack=new Stack<>();

        stack.push(start);

        while(!stack.empty()){
            Vertex v=stack.pop();

            ArrayList<Vertex> getV=getVertexList(v);

            if(!getV.isEmpty()){
                for(Vertex V:getV){
                    if(getV.get(0)==finish) return true;
                    if(!stack.contains(V)&&V!=finish)stack.push(V);
                }
            }
        }
        return false;
    }
    public boolean bfs(Vertex start,Vertex finish){
        if(start==null||finish==null)return false;
        else if(start==finish)return true;
        ArrayList<Vertex> list=new ArrayList<>();

        list.add(start);

        for(int i=0;i<list.size();++i){
            Vertex v=list.get(i);

            ArrayList<Vertex> getV=getVertexList(v);

            if(!getV.isEmpty()){
                for (Vertex V : getV) {
                    if (!list.contains(V))list.add(V);
                    if(V==finish)return true;
                }
            }
        }
        return false;
    }
    public ArrayList<ArrayList<Vertex>> fordMin(Vertex start, Vertex finish){
        if(!bfs(start,finish)||start==finish)return null;

        int vWeight[]=new int[Vertexes.size()],sum=0,min=999999999;
        boolean dupl=false;
        ArrayList<Vertex>list=new ArrayList<>();
        Vertex lastAdded=null;

        list.add(start);
        vWeight[0]=0;
        for(int i=1;i<vWeight.length;++i){
            vWeight[i]=999999999;
        }


        for (int i=0;i<list.size();++i){
            Vertex v=list.get(i);

            ArrayList<Vertex> getV=getVertexList(v);

            list.addAll(getV);

            for(Edge E:Edges){
                if(E.from==v) {
                    if (vWeight[E.from.number - 1] + vWeight[E.to.number - 1] > E.weight&&vWeight[E.from.number-1]+E.weight<vWeight[E.to.number-1])
                        vWeight[E.to.number - 1] = vWeight[E.from.number - 1] + E.weight;
                }
            }
        }

        Stack<Vertex> stack=new Stack<>();
        ArrayList<ArrayList<Vertex>>ways=new ArrayList<>();
        ArrayList<Vertex> getV;

        list.clear();
        list.add(start);

        stack.add(start);

        while (!stack.empty()&&!list.isEmpty()){
            Vertex v = stack.pop();

            getV = getVertexList(v);

            for (Vertex w:getV) {
                if (bfs(w, finish)) stack.push(w);
            }

            for (Edge E : Edges) {
                if (E.to == v && E.from==list.get(list.size()-1) && vWeight[E.to.number - 1] - vWeight[E.from.number - 1] == E.weight) {
                    list.add(v);
                    sum+=E.weight;
                    break;
                }
            }

            if(v!=finish)continue;

            if(!list.isEmpty()&&list.contains(finish)) {
                if(sum<min)min=sum;
                for(ArrayList<Vertex> s:ways){
                    if(s.equals(list)) {
                        dupl = true;
                        break;
                    }
                }
                if(!dupl)ways.add((ArrayList<Vertex>)list.clone());
                else if(stack.size()>1)stack.push(lastAdded);
            }

            Vertex w;

            while(!list.isEmpty()&&!stack.isEmpty()){

                w=list.get(list.size()-1);

                if((!bfs(w,stack.lastElement())||dupl)&&list.size()>1){
                    for(Edge e:Edges){
                        if(e.to==w && e.from==list.get(list.indexOf(w)-1)) {
                            sum -= e.weight;
                            break;
                        }
                    }
                    list.remove(w);

                    if(bfs(w,stack.lastElement())&&w!=stack.lastElement()){
                        dupl=false;
                        break;
                    }
                }else{
                    if(list.size()==1&&dupl)dupl=false;
                    lastAdded=stack.lastElement();
                    break;
                }
            }
        }
        System.out.println("min= "+min);
        return ways;
    }
    public ArrayList<ArrayList<Vertex>> belmanMin(Vertex start, Vertex finish){
        if(!bfs(start,finish)||start==finish)return null;

        ArrayList<ArrayList<Vertex>> ways=new ArrayList<>();
        int distance[][]=getMatrix(),vector[][]=new int[Vertexes.size()][Vertexes.size()],vertexCount=Vertexes.size(),min=999999999,workVector=0;
        boolean dupl=true;
        Vertex lastAdded=null;

        for(int i=0;i<vertexCount;++i){
            for(int j=0;j<vertexCount;++j){
                if(i!=j&&distance[i][j]==0)distance[i][j]=999999999;
            }
        }

        for(int j=0;j<vertexCount;++j){
            vector[0][j]=distance[j][finish.number-1];
        }

        for(int i=1;i<vertexCount;++i){
            for(int j=0;j<vertexCount;++j){
                for(int z=0;z<vertexCount;++z){
                    int rez=distance[j][z]+vector[i-1][z];
                    if(min>rez)min=rez;
                }
                vector[i][j]=min;
                min=999999999;
            }
            for(int j=0;j<vertexCount;++j){
                if(vector[i][j]!=vector[i-1][j]) {
                    dupl = false;
                    break;
                }
            }
            if(dupl) {
                workVector=i;
                break;
            }
            dupl=true;
        }

        ArrayList<Vertex> list=new ArrayList<>();
        Stack<Vertex> stack=new Stack<>();

        stack.add(start);
        list.add(start);
        ArrayList<Vertex>getV;
        dupl=false;

        while(!stack.isEmpty()){
            Vertex v = stack.pop();

            getV = getVertexList(v);

            for (Vertex w:getV) {
                if (bfs(w, finish)) stack.push(w);
            }
            if(distance[list.get(list.size()-1).number-1][v.number-1]==vector[workVector][list.get(list.size()-1).number-1]-vector[workVector][v.number-1]&&!list.contains(v))list.add(v);

            if(v!=finish)continue;

            if(!list.isEmpty()&&list.contains(finish)) {
                for(ArrayList<Vertex> s:ways){
                    if(s.equals(list)) {
                        dupl = true;
                        break;
                    }
                }
                if(!dupl)ways.add((ArrayList<Vertex>)list.clone());
                else if(stack.size()>1)stack.push(lastAdded);
            }

            Vertex w;

            while(!list.isEmpty()&&!stack.isEmpty()){

                w=list.get(list.size()-1);

                if((!bfs(w,stack.lastElement())||dupl)&&list.size()>1){

                    list.remove(w);

                    if(bfs(w,stack.lastElement())&&w!=stack.lastElement()){
                        dupl=false;
                        break;
                    }
                }else{
                    if(list.size()==1&&dupl)dupl=false;
                    lastAdded=stack.lastElement();
                    break;
                }
            }
        }

        System.out.println("min= "+vector[workVector][0]);
        return ways;
    }
}

    public static void menu(){
        System.out.println("1.Меню");
        System.out.println("2.Создать граф");
        System.out.println("3.Выбрать если граф взвешенный");
        System.out.println("4.Список смежности");
        System.out.println("5.Обход в глубину");
        System.out.println("6.Обход в ширину");
        System.out.println("7.Алгоритм Форда");
        System.out.println("8.Алгоритм Белмана-Коллаба");
        System.out.println("9.Закончить программу");
    }
    public static void main(String[] argv)throws java.io.IOException{
        Graph graph;
        ArrayList<ArrayList<Vertex>>f;



        int choice;
        boolean isGraph=false,haveWeight=false;


        BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));

        menu();
        while(true){
            do{
                choice=Integer.parseInt(reader.readLine());

                if(choice<1|choice>9) {

                    System.out.println("Выбранного пункта меню нет, попробуйте ещё раз");

                }else if(isGraph&&choice==2){

                    System.out.println("Граф уже создан");

                }else if(!isGraph&&(choice==3||choice==4||choice==5||choice==6||choice==7||choice==8)) {

                    System.out.println("Сначала создайте граф");
                }else if((choice==7||choice==8)&&!haveWeight){
                    System.out.println("Для этих пунктов граф должен быть взвешенным");
                }else break;
            }while(true);

            if(choice==9)break;

            switch (choice){

                case 1:menu();break;

                case 2:
                    graph=new Graph();
                    for (int i = 1; true; ++i) {

                        System.out.println("Вы хотите добавить вершину " + i + "?\n1.Да\n2.Нет");

                        int ch;

                        do {

                            ch = Integer.parseInt(reader.readLine());

                        } while (ch > 2 || ch < 1);

                        if (ch == 1) {

                            graph.addVertex(new Vertex(i));
                        } else break;
                    }
                    while (true) {

                        System.out.println("Вы хотите добавить дугу?\n1.Да\n2.Нет");

                        int ch;

                        do {

                            ch = Integer.parseInt(reader.readLine());

                        } while (ch > 2 || ch < 1);

                        if (ch == 1) {

                            System.out.println("Какие вершины она связывает?");

                            Vertex vSt = graph.vertexSearch(Integer.parseInt(reader.readLine())),
                                    vF = graph.vertexSearch(Integer.parseInt(reader.readLine()));

                            if (vSt != null && vF != null && !graph.containEdge(vSt, vF))graph.addEdge(vSt, vF);

                            else System.out.println("not found or yet exist");
                        } else break;
                    }
                    isGraph=true;
                    break;
                case 3:
                    int I=graph.Edges.size();
                    for(int i=0;i<I;++i){

                        Edge E=graph.Edges.get(i);

                        System.out.print(E.from.number+" - "+E.to.number+"=");

                        E.weight=Integer.parseInt(reader.readLine());
                    }
                    haveWeight=true;
                    break;
                case 4:
                    graph.smeList();
                    break;
                case 5:
                    System.out.println("Между какими звеньями провести обход?");
                    Vertex vSt = graph.vertexSearch(Integer.parseInt(reader.readLine())),
                            vF = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    if (vSt != null && vF != null)System.out.println(graph.dfs(vSt,vF));
                    else System.out.println("not found");
                    break;
                case 6:
                    System.out.println("Между какими звеньями провести обход?");
                    vSt = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    vF = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    if (vSt != null && vF != null)System.out.println(graph.bfs(vSt,vF));
                    else System.out.println("not found");
                    break;
                case 7:
                    f=null;
                    System.out.println("Между какими звеньями высчитать путь?");
                    vSt = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    vF = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    if(vSt!=null&&vF!=null)f=graph.fordMin(vSt,vF);
                    if(f!=null){
                        for (ArrayList<Vertex> W : f) {
                            for (Vertex w : W) {
                                 System.out.print(w.number);
                            }
                            System.out.println();
                        }
                    }
                    break;
                case 8:
                    f=null;
                    System.out.println("Между какими звеньями высчитать путь?");
                    vSt = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    vF = graph.vertexSearch(Integer.parseInt(reader.readLine()));
                    if(vSt!=null&&vF!=null)f=graph.belmanMin(vSt,vF);
                    if(f!=null){
                        for (ArrayList<Vertex> W : f) {
                            for (Vertex w : W) {
                                System.out.print(w.number);
                            }
                            System.out.println();
                        }
                    }
                    break;
            }
        }
    }
}

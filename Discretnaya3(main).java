import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Lab2and3 {
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

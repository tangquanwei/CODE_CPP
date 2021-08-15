阶（Order）：图G中顶集V的大小称作图G的阶。
子图（Sub-Graph）：图G'称作图G的子图如果 V(G')subseteq V(G)以及 E(G')subseteq E(G)。
生成子图（Spanning Sub-Graph）：指满足条件 V(G')=V(G)的G的子图G'。
度（Degree）：一个顶点的度是指与该顶点相关联的总边数，顶点 v的度记作 d(v)。度和边有如下关系： sum _vin Vd(v)=2left|Eright|。
出度（Out-degree）和入度（In-degree）：对有向图而言，顶点的度还可分为出度和入度。一个顶点的出度为 d_o，是指有 d_o条边以该顶点为起点，或说与该点关联的出边共有 d_o条。入度的概念也类似。
邻接矩阵（Adjacency matrix）
自环（Loop）：若一条边的两个顶点相同，则此边称作自环。
路径（Path）：从顶点u到顶点v的一条路径是指一个序列 v_0,e_1,v_1,e_2,v_2,...e_k,v_k， e_i的起点终点为 v_i-1及 v_i； k称作路径的长度； v_0=u，称为路径的起点； v_k=v，称为路径的终点。如果 u=v，称该路径是闭的，反之则称为开的；如果 v_1,...,v_k两两不等，则称之为简单路径（Simple path，注意， u=v是允许的）。
行迹（Trace）：如果路径 P(u,v)中边各不相同，则该路径称为 u到 v的一条行迹。
轨道（Track）：即简单路径。
闭的行迹称作回路（Circuit），闭的轨道称作圈（Cycle）。（现存文献中的命名法并无统一标准。比如在另一种定义中，walk对应上述的path，path对应上述的track，trail对应上述的trace。）
距离（Distance）： 从顶点 u出发到顶点 v的最短路径若存在，则此路径的长度称作从 u到 v的距离。若从 u到 v根本不存在路径，则记该距离为无穷（ infty ）。
距离矩阵（Distance matrix）
桥（Bridge）：若去掉一条边，便会使得整个图不连通，该边称为桥。

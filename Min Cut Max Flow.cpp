Min Cost Max Flow (My Code for Building String : Codeforces)
#define MAXN 3005
struct MCMF {
  typedef lld ctype;	
  struct Edge { lld x, y; lld cap, cost; };
  vector<Edge> E;      vector<lld> adj[MAXN];
  lld N, prev[MAXN];   ctype dist[MAXN], phi[MAXN];

  MCMF(lld NN) : N(NN) {}

  void add(lld x,lld y,ctype cap,ctype cost) {  // cost >= 0
    cost += EPS;
      //   printf("Adding (%d, %d) having (%d, %d)\n", x, y, cap, cost);
    Edge e1={x,y,cap,cost}, e2={y,x,0,-cost};
    adj[e1.x].push_back(E.size()); E.push_back(e1);
    adj[e2.x].push_back(E.size()); E.push_back(e2);
  }

  void mcmf(lld s,lld t, ctype &flowVal, ctype &flowCost) {
    lld x;
    flowVal = flowCost = 0;  memset(phi, 0, sizeof(phi));
    while (true) {
      for (x = 0; x < N; x++) prev[x] = -1;
      for (x = 0; x < N; x++) dist[x] = INF;
      dist[s] = prev[s] = 0;

      set< pair<ctype, lld> > Q;
      Q.insert(make_pair(dist[s], s));
      while (!Q.empty()) {
        x = Q.begin()->second; Q.erase(Q.begin());
        tr(it,adj[x]) {
          const Edge &e = E[*it];
          if (e.cap <= 0) continue;
          ctype cc = e.cost + phi[x] - phi[e.y];                    // ***
          if (dist[x] + cc + EPS < dist[e.y]) {
            Q.erase(make_pair(dist[e.y], e.y));
            dist[e.y] = dist[x] + cc;
            prev[e.y] = *it;
            Q.insert(make_pair(dist[e.y], e.y));
          }
        }
      }
      if (prev[t] == -1) break;

      ctype z = INF;
      for (x = t; x != s; x = E[prev[x]].x) z = min(z, E[prev[x]].cap);
      for (x = t; x != s; x = E[prev[x]].x)
        { E[prev[x]].cap -= z; E[prev[x]^1].cap += z; }
      flowVal += z;
      flowCost += z * (dist[t] - phi[s] + phi[t]);
      for (x = 0; x < N; x++) if (prev[x] != -1) phi[x] += dist[x];     // ***
    }
  }
};

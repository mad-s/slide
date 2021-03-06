/*!slide plugin_config
dir false
weight false
list false
read true
var g
class Graph
list_n n
list_ed ed
ty lli
*/

class $class$ {
  public:
    $ty$ nodes, edges;
    //!slide plugin_if weight
    vector<vector<pair<long, long>> adj;
    //!slide plugin_end_if
    //!slide plugin_if !weight
    vector<vector<long>> adj;
    //!slide plugin_end_if

    //!slide plugin_if !list
    void read() {
      cin >> nodes >> edges;
      adj.resize(nodes);
      for($ty$ i = 0; i < edges; i++) {
        //!slide plugin_if weight
        $ty$ a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        //!slide plugin_if !dir
        adj[b].emplace_back(a, c);
        //!slide plugin_end_if
        //!slide plugin_end_if
        //!slide plugin_if !weight
        $ty$ a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        //!slide plugin_if !dir
        adj[b].push_back(a);
        //!slide plugin_end_if
        //!slide plugin_end_if
      }
    }
    //!slide plugin_end_if

    //!slide plugin_if list
    //!slide plugin_if weight
    void from_list($ty$ n, vector<tuple<$ty$, $ty$, $ty$>>& list) {
      adj.resize(n);
      for (auto& edge : list) {
        adj[get<0>(edge)].emplace_back(get<1>(edge), get<2>(edge));
        //!slide plugin_if !dir
        adj[get<1>(edge)].emplace_back(get<0>(edge), get<2>(edge));
        //!slide plugin_end_if
      }
    }
    //!slide plugin_end_if
    //!slide plugin_if !weight
    void from_list($ty$ n, vector<pair<$ty$, $ty$>>& list) {
      adj.resize(n);
      for (auto& edge : list) {
        adj[edge.first].push_back(edge.second);
        //!slide plugin_if !dir
        adj[edge.second].push_back(edge.first);
        //!slide plugin_end_if
      }
    }
    //!slide plugin_end_if
    //!slide plugin_end_if
};

//!slide plugin_input
//!slide plugin_if read
$class$ $var$;
//!slide plugin_if list
$var$.from_list($list_n$, $list_ed$);
//!slide plugin_end_if
//!slide plugin_if !list
$var$.read();
//!slide plugin_end_if
//!slide plugin_end_if

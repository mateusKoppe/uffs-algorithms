const depthFirstSearch = (graph, at, _visitedNodes) => {
  const visitedNodes = _visitedNodes
    ? _visitedNodes
    : graph.reduce((acc, _) => [...acc, false], []);

  if (visitedNodes[at]) return visitedNodes;

  visitedNodes[at] = true;

  return graph[at].reduce(
    (acc, node) => depthFirstSearch(graph, node, acc),
    visitedNodes
  );
};

const initialGraph = [
  [1, 3],
  [0, 2],
  [1, 4],
  [0, 4],
  [2, 3, 5, 6],
  [4],
  [4, 7],
  [6],
  [],
];
depthFirstSearch(initialGraph, 0); //=

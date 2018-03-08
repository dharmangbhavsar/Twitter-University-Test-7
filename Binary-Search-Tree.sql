# Problem is something like this ---  https://www.hackerrank.com/challenges/binary-search-tree-1/problem
SELECT ID, CASE WHEN P_ID IS NULL 
THEN 'ROOT' 
WHEN (SELECT COUNT(*) FROM TREE WHERE P_ID = T.ID) 
THEN 'INNER' 
ELSE 'LEAF' END FROM TREE as T ORDER BY ID
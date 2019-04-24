# Write your MySQL query statement below
SELECT MIN(ABS(a.x - b.x)) as shortest
FROM point a, point b
WHERE a.x != b.x
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select max(result.salary) from (select *, dense_rank() over(order by Employee.salary desc) as rankno from Employee) as result
      where result.rankno=N

  );
END
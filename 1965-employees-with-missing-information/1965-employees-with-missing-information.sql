WITH all_employee_info_cte AS
(
    SELECT employee_id FROM Employees
    UNION ALL
    SELECT employee_id FROM Salaries
)

SELECT employee_id
FROM all_employee_info_cte
GROUP BY employee_id
HAVING COUNT(*) != 2
ORDER BY 1;
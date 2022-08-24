SELECT employee_id, 
    case 
        when 
            MOD(employee_id,2) = 1 AND
            name NOT LIKE 'M%'
            THEN salary
            else 0
        end
        as bonus
        FROM Employees
        ORDER BY employee_id;

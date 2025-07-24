SELECT 
  ce.visited_on,
    (
        SELECT SUM(amount)
            FROM Customer
                WHERE visited_on BETWEEN DATE_SUB(ce.visited_on, INTERVAL 6 DAY) AND ce.visited_on
                  ) AS amount,
                    ROUND((
                        SELECT SUM(amount) / 7
                            FROM Customer
                                WHERE visited_on BETWEEN DATE_SUB(ce.visited_on, INTERVAL 6 DAY) AND ce.visited_on
                                  ), 2) AS average_amount
                                  FROM Customer ce
                                  WHERE ce.visited_on >= (
                                    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
                                      FROM Customer
                                      )
                                      GROUP BY ce.visited_on
                                      ORDER BY ce.visited_on;
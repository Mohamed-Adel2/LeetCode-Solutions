SELECT pr.product_id, COALESCE (ROUND(SUM(pr.price * tu.units)/ SUM(tu.units), 2) , 0) AS average_price
FROM 
    Prices pr
LEFT OUTER JOIN 
    UnitsSold tu ON pr.product_id = tu.product_id AND tu.purchase_date Between pr.start_date AND pr.end_date
GROUP BY 
    pr.product_id;
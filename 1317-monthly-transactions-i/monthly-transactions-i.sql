SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    (SELECT COUNT(*) FROM Transactions t WHERE DATE_FORMAT(t.trans_date, '%Y-%m') = month && (tt.country = t.country || (t.country IS NULL && tt.country IS NULL)) && state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    COALESCE((SELECT SUM(amount) FROM Transactions t WHERE DATE_FORMAT(t.trans_date, '%Y-%m') = month && (tt.country = t.country || (t.country IS NULL && tt.country IS NULL)) && state = 'approved'), 0) AS approved_total_amount
    
FROM Transactions tt
GROUP BY country, month
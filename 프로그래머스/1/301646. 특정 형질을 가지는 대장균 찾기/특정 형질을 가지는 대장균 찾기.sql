-- 코드를 작성해주세요
select count(*) as COUNT from ecoli_data
where (genotype & b'100' > 0 or genotype & b'001' > 0) and genotype & b'10' = 0
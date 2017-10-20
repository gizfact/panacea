select P1,P2,P3 from
(
    select
        replace(case when a.PHONE1 is null then '' else a.PHONE1 end,' ','') as P1,
        replace(case when a.PHONE2 is null then '' else a.PHONE2 end,' ','') as P2,
        replace(case when a.PHONE3 is null then '' else a.PHONE3 end,' ','') as P3
    from Clients a where a.ALIVE>0 and (a.PHONE1 is not null or a.PHONE2 is not null or a.PHONE3 is not null)
)
where char_length(P1)=11 or char_length(P2)=11 or char_length(P3)=11

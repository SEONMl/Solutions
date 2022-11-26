def solution(id_list, k):
    days=len(id_list)
    # 1_000 * 5_000
    coupon={}
    totalCoupons=0
    for day in range(days):
        idOfDay=set(id_list[day].split())
        for id in idOfDay:
            value=coupon.setdefault(id,0)
            if(value>=k):
                continue
            else:
                coupon[id]=value+1
                totalCoupons+=1

    return totalCoupons

print(solution(["A B C D", "A D", "A B D", "B D"], 2))
print(solution(
["JAY", "JAY ELLE JAY MAY", "MAY ELLE MAY", "ELLE MAY", "ELLE ELLE ELLE", "MAY"], 3))
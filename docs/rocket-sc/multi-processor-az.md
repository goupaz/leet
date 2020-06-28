## Parallelism at Multi-Processor level
_İC dizaynı zamanı hər bir komponentin əlavəsi transistorun ölçüsü və digər faktorlar seçildiyi zaman əsas nəzərə alının məsələ power-efficient olmasıda nəzərə alınır_
Bəzi mənbələrdə _SpaceX_ özü tərəfindən bildirilir ki kosmosa göndərilən roketlərdə fault-tolerance məqsədi ilə yəni CPU-ları *radiation-hardened* etmək üçün redundancy təmin etmək üçün *Dual modular redundancy* mexanizmini istifadə edirlər əslində cihazlar özləri radion-hardened-dir ancaq bunu tam təmin etmək bahalı olduğuna görə onlar fərqli metod istifadə edilər ki cihazlar iyonlaşdırıcı radiasiyadan və kosmik işığlardan hesablamaların dəyərlərində hər hansı bir problem olduğu zaman bunu fix edə bilsinlər. Məntiq isə bundan ibarətdir ki prosessorlar independent parallel öz core-ları üzərində hesablamaları edəcəklər və daha sonra _voting_ sistemi bunların hansında error-lar yarandığını detect edəcək.

e.g formaya baxaq
```
Bu halda hesablama tək 4 (F) Ghz CPU-da core-ların və yaxud threadların üzərində getdiyi üçün hər hansı bir redundancy yoxdur.

+------------+
|            |
| Single CPU |
|    4 GHZ   |
|            |
+------------+

Bu halda 4 unit halında F/4 göstərilir. Yəni hesablama paralel olaraq bütün cihazlar üzərində aparılır. 
+------------+               +------------+
|            |               |            |
|            |               |            |
|   CPU 0    |               |   CPU 1    |
|   1 GHZ    |               |   1 GHZ    |
|            |               |            |
+------------+               +------------+

+------------+               +------------+
|            |               |            |
|            |               |            |
|   CPU 2    |               |   CPU 3    |
|   1 GHZ    |               |   1 GHZ    |
|            |               |            |
+------------+               +------------+

```
_Dynamic power consumption logic gate-lərin (transistorların) activity səbəbindən yaranır_

CPU tərəfindən dynamic power consumption - CPU tezliyinə və həmçinin CPU voltajına mütənasibdir.

<img src="https://render.githubusercontent.com/render/math?math=P_{dyn}=CV^{2}f&mode=inline">

Burada digər bir məsələ isə aşağıda qeyd etdiyim dynamic və short-circuit clock frequency depended hesab edilir. Yəni biz tezliyi azaltdığca power consumption özüdə azalmağa başlayır. Bu səbəbdən buda SpaceX üçün power efficiency sayıla bilər ancaq voting sistemi + NoC (network on chip) və yaxud CPU-lar arasında (die-to-die) hansı texnologiya istifadə edilirsə burada da yəgin ki əlavə power consumption var. Həmçinin bottleneck yaranmaması üçün high-bandwitdh lazım ola bilər böyük dataların qısa müddətdə transfer edilə bilməsi üçün.


### Power Consumption
_Power efficiency haqqında növbəti VLSİ design dokumentasiyalarında ətraflı qeyd edəcəm_ 
*Bu sadəcə informativdir*

CMOS integrated circuit səviyyəsində power consumption dynamic power və static power-dan yaranır. Yəni bu iki halda İC üzərində dissipation baş verir.
<p align="center">
<img src="https://raw.githubusercontent.com/goupaz/leet/master/assets/Screenshot_2020-06-28%20lecture14%20ppt%20-%20lecture9%20pdf.png" style="max-width:100%;" width="450" height="200">
</p>

Yuxarıdaki şəkildə görüldüyü kimi capacitor PMOS transistor vasitəsi ilə charge edildiyində voltage 0-dan Vdd dəyərinə doğru yüksəlir və power supplydan müəyyən enerji əldə edilir. Bu enerji PMOS device-da itirilir hansi ki qalan enerji capacitorda saxlanır. Həmçinin high-to-low transition zamanı capacitor discharge olunduğu zaman saxlanılan müəyyən enerji NMOS transistorundan leak olur.
<p align="center">

<img src="https://raw.githubusercontent.com/goupaz/leet/master/assets/Dissipation-in-CMOS.jpg" style="max-width:100%;" width="450" height="200">
</p>
Bu dissipation prosesi birçox halda Switching power (in capacitance) və Short-circuit (through transistor) adlandırılır. Aşağıdaki şəkildə hər iki hal göstərilib.
<p align="center">
<img src="https://raw.githubusercontent.com/goupaz/leet/master/assets/Screenshot_2020-06-28%20Power%20Consumption%20-%20Semiconductor%20Engineering(2).png" style="max-width:100%;" width="500" height="100">
</p>

<p align="center">
<img src="https://raw.githubusercontent.com/goupaz/leet/master/assets/Screenshot_2020-06-28%20Power%20Consumption%20-%20Semiconductor%20Engineering(1).png" style="max-width:100%;" width="500" height="100">
</p>

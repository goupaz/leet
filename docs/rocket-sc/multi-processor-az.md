## Parallelism at Multi-Processor level
_Note: IC dizaynında hər bir komponentin əlavəsi zamanı, transistorun sayının artımı və power-efficiency nəzərə alınır_

Bəzi mənbələrdə bildirilir ki SpaceX tərəfindən kosmosa göndərilən roketlərdə fault-tolerance/redundancy məqsədi ilə (yəni CPU-ları *radiation-hardened* etmək üçün) *Dual modular redundancy* mexanizmini istifadə edirlər. Əslində cihazlar özləri *radion-hardened*-dir, ancaq bunu tam təmin etmək bahalı olduğuna görə onlar fərqli metod istifadə edirlər ki, cihazlarda iyonlaşdırıcı radiasiyadan və kosmik işıqların təsirindən hesablamaların dəyərlərində hər hansı bir problem olduğu zaman bunu fix/detect edə bilsinlər. Məntiq isə bundan ibarətdir ki, prosessorlar _independent_, yəni parallel olaraq öz core(ları) üzərində hesablamaları edəcəklər və daha sonra _voting_ sistemi bunların arasında hər hansı bir uyğunsuzluq olub olmadığını aşkar ediləcəkdir.

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

CPU tərəfindən dynamic power consumption - CPU tezliyinə və həmçinin CPU voltajına düz mütənasibdir.

<img src="https://render.githubusercontent.com/render/math?math=P_{dyn}=CV^{2}f&mode=inline">

Burada digər bir məsələ isə aşağıda qeyd etdiyim dynamic və short-circuit clock tezlikdən (f) aslı hesab edilir. Yəni, biz tezliyi azaltdıqca power consumption özü də azalmağa başlayır (dediyim kimi düz mütənasibdir). Bu səbəbdən buda SpaceX üçün power efficiency sayıla bilər ancaq voting sistemi (Bu haqda tam fikrim yoxdur hansı mexanizmdən istifadə edirlər) + Interconnection üçün NoC (network on chip) və yaxud digər CPU-lar arası (e.g die-to-die) hansı (communication üçün) texnologiyanı istifadə edirsə burada da yəgin ki, əlavə power consumption nəzərə alıb. Həmçinin bottleneck yaranmaması üçün high-bandwidth+frequency lazım ola bilər ki, böyük datalar qısa müddətdə transfer edilə bilsin.


### Power Consumption
_Power efficiency haqqında növbəti VLSI design dokumentasiyalarında ətraflı qeyd edəcəm_ 
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

# DmetaCT
# DMETA Coding Test 결과물
## 가정 
1. string을 그대로 불러왔기에, std namespace 및 string header를 사용함.
2. 기본 cpp main 프로그램으로 입출력을 확인하기 위해 iostream header를, 연산시간을 확인하기 위해 ctime header를 사용함.
3. 정수의 나눗셈이므로 무한소수이더라도 반드시 순환소수여야 함. 또한 반복 구간을 구해야 하므로 long division (schoolbook method) 방식을 사용함.
4. string 값을 return해야하므로, 최대 65535개의 문자를 가질 수 있으며, 이에 따라 순환구문을 구하는 과정이 50000개 자릿수를 넘는 경우 조건 내에서 구할 수 없다고 가정, ... 을 붙여서 연산을 종료함.
## 연산 속도를 올리기 위해 활용한 방법
1. 나눗셈과 나머지를 구하여 반복하는 것이 일반적 방식이나, 컴퓨터의 작동 방식은 나눗셈보다는 곱셈의 속도가 훨씬 빠르며, 일반적 덧셈이나 곱셈보다는 bit 이동이 더 빠름. 따라서 bit이동을 통한 반복뺄셈 방식으로 나누기를 수행함.
2. 포인터를 사용해 나누기의 값과 함께 나머지의 값이 계속해서 남을 수 있도록 작성함. 
3. 일반적 나눗셈의 방식이면 최대공약수를 구하는 것도 이점이 될 수 있으나, 비트연산을 통한 값 비교를 수행하였으므로 최대공약수를 구해서 연산하는데 따른 이점이 없어 사용하지 않음.
4. 비트연산을 통하여 순환소수 부분을 계산하는 것도 고려할 수 있으나, 10진수의 0.1이 2진법상에서는 순환소수인 것과 같이 유리수의 순환부에서 적용할 수 없으므로, 나머지를 10배씩 곱하는 방식을 유지하였음.
5. nominator와 denominator가 충분히 커, 나머지를 10배 하였을 때 int의 범위를 초과할 수 있는 경우가 있으므로, 나눗셈시에 int64_t 로 선언함. 
## 추가 고려 가능 사항
1. 나머지 값의 중복 검색과 나눗셈의 과정을 병렬로 연산할 수 있다면, 일부 소수의 큰 수 계산의 경우 연산을 더 빠르게 할 수 있을 것이라 판단됨.
2. 초거대 Prime number 의 경우(메르센 소수 등), 여전히 연산에 엄청난 시간을 들여야함(1초에 가까움). 32비트 정수를 넘어서는 나눗셈의 경우, 일정 이상 연산시간이 걸리면, 연산을 종료 후 Newton 방식 등의 근사법으로 전환하는 로직을 사용할 필요성이 있음.
   1. 혹은 거대 Prime number의 경우 역수를 미리 입력하여 연산시 활용하는 것도 가능함.
## 사용법
1. 단독 프로그램으로 사용할 경우.
   1. main.cpp 를 컴파일 후 실행, 연산을 할 정수값 2개를 입력.
2. Solution class 로 사용할 경우 아래 두개의 함수와 클래스를 사용.
   1. int bitDivide(int64_t *a, int64_ b) 함수 (line 6 to line 18) <-- bit 연산을 통해 나눗셈을 하는 함수
   2. class Solution 클래스 (line 19 to line 80) <-- 전처리 및 나눗셈의 나머지를 비교하여 순환여부와 순환구간을 확인하여 유리수를 return하는 전체 클래스. 
## 결과물 
3가지 예시 결과물과 함께, 추가적으로 5자리의 소수인 61631을 나누어보았으며, 3가지 예시의 경우 시간이 거의 들지 않고 실행할 수 있었으며, 1/61631의 경우, 0.325초의 연산을 통해 30815자리의 순환소수 부분을 연산할 수 있음을 확인하였음.
(50000자리를 넘어서 ...으로 처리되는 것을 보려면, numeratord에 1, Denominator: 2147483647(메르센 소수)를 입력하면 확인 할 수 있음)
테스트 결과물은 아래와 같음.
- Case 1
PS C:\Users\redvu\OneDrive\바탕 화면\DmetaTest> .\main.exe
Type numerator: 1
Type Denominator: 2
"0.5"
0 time passed(unit is second)
- Case 2
PS C:\Users\redvu\OneDrive\바탕 화면\DmetaTest> .\main.exe
Type numerator: 2
Type Denominator: 1
"2"
0 time passed(unit is second)
- Case 3
PS C:\Users\redvu\OneDrive\바탕 화면\DmetaTest> .\main.exe
Type numerator: 4
Type Denominator: 333
"0.(012)"
0.001 time passed(unit is second)
- Extra Case
PS C:\Users\redvu\OneDrive\바탕 화면\DmetaTest> .\main.exe
Type numerator: 1
Type Denominator: 61631
"0.(00001622560075286787493306939689442001590108873781051743440800895653161558306696305430708571984877740098327140562379322094400545180185296360597751131735652512534276581590433385796109100939462283591049958624718080186918920673037919228959452223718583180542259577160844380263179244211516931414385617627492657915659327286592786097905274942804757346140740860930375947169443948662199217926043711768428226055069688955233567522837533059661533968295176128896172380782398468303288929272606318248933166750498937223150687154191883954503415488958478687673411108046275413347179179309113919942885885349905080235595722931641544028167642906978630883808473008713147604290048839058266132303548538884652204247862277100809657477568106959160162905031558793464328016744819976959646930927617595041456409923577420453992309065243140627281725105872044912462883938277814736090603754604014213626259512258441368791679511933929353734322013272541415845921695250766659635573007090587529003261345751326442861546948775778423196118836299914004316009800262854732196459573915724229689604257597637552530382437409745095812172445684801479774788661550193895928996771105450179292888319190018010416835683341175707030552806217650208498969674352192889941750093297204328990280865149032142915091431260242410475247846051500056789602635037562265742889130470055653810582336811020428031347860654540734370690074800019470720903441449919683276273304019081306485372620921289610747837938699680355665168502863818532881179925686748551865132806542162223556327173013580827830150411318979085200629553309211273547403092599503496616962243027048076455030747513426684622998166507114925930132563158150930538203176972627411529911894987911927439113433174863299313657088153688890331164511366033327383946390615112524541221138712660836267462802810274050396715938407619542113546754068569388781619639467151271275818987198001005987246677808245850302607454040985867501744252080933296555304960166150151709367039314630624198860962827148675179698528338011714883743570605701676104557771251480586068699193587642582466615826450974347325209715889730817283509921954860378705521571936200937839723515763171131411140497476919082929045447907708782917687527380701270464538949554607259333776833087245055248170563515114147101296425500154143207152244811864159270496990151060343009199915626876085087050348039136149015917314338563385309341078353426035598968051792117603154256786357514886988690756275251091171650630364589248916941149746069348217617757297463938602326751147961253265402151514659830280216125002028200094108484366633674611802501987636092226314679301001119566451947883370381788385714981097175122908925702974152618000681475231620450747188914669565640667845726988041732245136376174327854488812448280897600233648650841297399036199315279648228975677824471451055475328974055264396164267982022034365822394574159108240982622381593678505946682675926076162969933961804935827749022407554639710535282568837111194041959403546916324576917460368970161120215475977998085379111161590757897811166458438123671528938358942739854943129269361198098359591763885057844266683973974136392399928607356687381350294494653664551930035209553633723288604760591260891434505362561048822832665379435673605815255309827846376012071846960133698950203631289448491830410020931024971199558663659521993801820512404471775567490386331553925784102156382340056140578604922847268420113254693255017767032824390323051710989599389917411692167902516590676769807402119063458324544466258863234411254076682189158053576933685969723028995148545374892505395012250328568415245574467394655287112005321997046940662978046762181369765215557106001849718485826937742369911245963881812724116110398987522513021044604176469633788191007772062760623712092940241112427187616621505411237851081436290178643864289075303013094059807564375070987003293796952832178611413087569567263227921013775535039184825818175917963362593500024338401129301812399604095341630023851633106715776151612013434797423374600444581460628579773166101474907108435689831416008177702779445408966266976034787688014148723856500786941636514091934253865749379370771202803783810095568788434391783355778747708133893657412665703947688663172753971215784264412389868734889909298891791468579124142071360192111112913955639207541659229932988268890655676526423390826045334328503512842562995894923009524427641933442585711735977024549333939089094773733997501257484058347260307312878259317551232334377180315101166620694131200207687689636708799143288280248576203533935843974623160422514643604679463257127095130697214064350732585873991984553228083269783063717934156512144862163521604387402443575473381901964920251172299654394703963914263925621846148853661306809884635978647109409225876588080673686943259074167221041359056319060213204393892683876620531875192679008940306014830199088121237688825428761499894533595106358812935048920186269896642923204231636676347941782544498710064740147003942820982946893608735863445344063863964563287955736561146176437182586685272022196621829923252908438934951566581752689393324787850270156252535250117635605458292093264753127484545115282893349126251399458064934854212977235482143726371468903636157128717690772500851844039525563433986143336957050834807158735052165306420470217909818111015560351122000292060813551621748795249144099560286219597280589313819344161217569080495205334977527542957277993217698885301228277976992098132433353344907595203712417452256169784686278009443299638169103211046388992552449254433645405721146825461212701400269344972497606723888951988447372263958073047654589411172948678424818678911586701497622949489704856322305333354967467670490499910759195859226687868118317080689912544011942042154110755950739076114293131703201311028540831724294592007269069137284807970015089808700167123687754539111810614788012526163781213999448329574402492252275640505589719459362982914442407230127695477925070175723256153559085525141568366568772208791030487903814638736999237396764615209878145738345962259252648829322905680582823579043014067595852736447566971167107462153786243935681718615631743765312910710519056968084243319108890006652496308675828722558452726712206519446382502312148107283672177962389057454852265905145137998734403141276305755220587042235238759715078450779640116175301390533984520776881764047313851795362723304830361344128766367574759455468838733754117246191040223264266359461959079034901267219418798981032272719897454203241875030423001411627265499505119177037529814541383394720189515016793496779218250555726825785724716457626843633885544612289270010222128474306761207833720043484610017685904820625983677045642614917817332186724213464003504729762619460985542989729194723434635167367071765832129934610828965942464019730330515487335918612386623614739335723905177589200240138891142444549009427074037416235336113319595658029238532556667910629391053203744868653761905534552416803232139669971280686667423861368467167496876571855072934075384141097824146939040417971475393876458275867664000259609612045885998929110350310720254417419804968278950528143304505849329071408868913371517580438415732342489980691535104087228829647417695640181077704402005484253054469341727377456150313965374567993379954892829907027307686067076633512355794973308886761532345735100842108679073842709026301698820398825266505492365854845775664843990848761175382518537748860151547111031785951874868166993882948516168811150232837370803654005289545845434927228180623387580925183754928526228683617010919829306680079829955704109944670701432720546478233356590027745777287404066135548668689458227190861741655984812837695315669062647044506822865116580941409355681394103616686407814249322581168567766221544352679657964336129545196410897113465626064805049406954292482679171196313543508948418815206633025587772387272638769450438902500365076016939527185994061430124450357774496600736642274180201521961350619006668721909428696597491522123606626535347471240122665541691681134494004640521815320212230857847511804124547711379013807986240690561568042056757151433531826515876750336681215622008404861189985559215329947591309568236763966185848031023348639483376872028686862131070402881666693709334588113124888448994824033359835147896350862390680014927552692638444938423845142866414629001638785676039655368240009086336421606009962518862260875208904609693173889763268485015657704726517499310411968003115315344550631987149324203728643053009037659619347406337719654070191948856906426960458210965260988788109879768298421249046745955769012347682172932452824065811036653632100728529473803767584494815920559458713958884327692232804919602148269539679706641138388148821210105304148886112508315620385844785903198065908390258149307978127890185134104590222452986321818565332381431422498418003926595382194025733802794048449643848063474550145219126738167480650971102205059142314744203404131037951680160957959468449319336048417192646557738800279080332949327448848793626584024273498726290340899871817754052343788028751764534081874381398971296912268176729243400236893770991870974022813194658532232155895572033554542356930765361587512777660592883451509792150054355762522107381025782479596307053268647271665233405266830004380912203274326231928737161493404293293959208839707290162418263536207428080024662913144359169898265483279518424169654881471986500300173613928055686261783842546770294170141649494572536548165695834888286738816504681085817202381918190521004040174587464100858334279826710583959371095714818841167594230176372280183673800522464344242345572844834580000324512015057357498661387937888400318021774756210348688160179130632311661339261086141714396975548019665428112475864418880109036037059272119550226347130502506855316318086677159221820187892456718209991724943616037383784134607583845791890444743716636108451915432168876052635848842303386282877123525498531583131865457318557219581054988560951469228148172186075189433888789732439843585208742353685645211013937791046713504567506611932306793659035225779234476156479693660657785854521263649786633350099787444630137430838376790900683097791695737534682221609255082669435835861822783988577177069981016047119144586328308805633528581395726176761694601742629520858009767811653226460709707776930440849572455420161931495513621391832032581006311758692865603348963995391929386185523519008291281984715484090798461813048628125456345021174408982492576787655562947218120750920802842725251902451688273758335902386785870746864402654508283169184339050153331927114601418117505800652269150265288572309389755155684639223767259982800863201960052570946439291914783144845937920851519527510506076487481949019162434489136960295954957732310038779185799354221090035858577663838003602083367136668235141406110561243530041699793934870438577988350018659440865798056173029806428583018286252048482095049569210300011357920527007512453148577826094011130762116467362204085606269572130908146874138014960003894144180688289983936655254660803816261297074524184257922149567587739936071133033700572763706576235985137349710373026561308432444711265434602716165566030082263795817040125910661842254709480618519900699323392448605409615291006149502685336924599633301422985186026512631630186107640635394525482305982378997582385487822686634972659862731417630737778066232902273206665476789278123022504908244227742532167253492560562054810079343187681523908422709350813713877756323927893430254255163797439600201197449335561649170060521490808197173500348850416186659311060992033230030341873407862926124839772192565429735035939705667602342976748714121140335220911554250296117213739838717528516493323165290194869465041943177946163456701984390972075741104314387240187567944703152634226282228099495383816585809089581541756583537505476140254092907789910921451866755366617449011049634112703022829420259285100030828641430448962372831854099398030212068601839983125375217017410069607827229803183462867712677061868215670685207119793610358423520630851357271502977397738151255050218234330126072917849783388229949213869643523551459492787720465350229592250653080430302931966056043225000405640018821696873326734922360500397527218445262935860200223913290389576674076357677142996219435024581785140594830523600136295046324090149437782933913128133569145397608346449027275234865570897762489656179520046729730168259479807239863055929645795135564894290211095065794811052879232853596404406873164478914831821648196524476318735701189336535185215232593986792360987165549804481510927942107056513767422238808391880709383264915383492073794032224043095195599617075822232318151579562233291687624734305787671788547970988625853872239619671918352777011568853336794794827278479985721471337476270058898930732910386007041910726744657720952118252178286901072512209764566533075887134721163051061965569275202414369392026739790040726257889698366082004186204994239911732731904398760364102480894355113498077266310785156820431276468011228115720984569453684022650938651003553406564878064610342197919877983482338433580503318135353961480423812691664908893251772646882250815336437831610715386737193944605799029709074978501079002450065713683049114893478931057422401064399409388132595609352436273953043111421200369943697165387548473982249192776362544823222079797504502604208920835293926757638201554412552124742418588048222485437523324301082247570216287258035728772857815060602618811961512875014197400658759390566435722282617513913452645584202755107007836965163635183592672518700004867680225860362479920819068326004770326621343155230322402686959484674920088916292125715954633220294981421687137966283201635540555889081793253395206957537602829744771300157388327302818386850773149875874154240560756762019113757686878356671155749541626778731482533140789537732634550794243156852882477973746977981859778358293715824828414272038422222582791127841508331845986597653778131135305284678165209066865700702568512599178984601904885528386688517142347195404909866787817818954746799500251496811669452061462575651863510246466875436063020233324138826240041537537927341759828657656049715240706787168794924632084502928720935892651425419026139442812870146517174798396910645616653956612743586831302428972432704320877480488715094676380392984050234459930878940792782852785124369229770732261361976927195729421881845175317616134737388651814833444208271811263812042640878778536775324106375038535801788061202966039817624247537765085752299978906719021271762587009784037253979328584640846327335269588356508899742012948029400788564196589378721747172689068812772792912657591147312229235287436517337054404439324365984650581687786990313316350537878664957570054031250507050023527121091658418652950625496909023056578669825250279891612986970842595447096428745274293780727231425743538154500170368807905112686797228667391410166961431747010433061284094043581963622203112070224400058412162710324349759049828819912057243919456117862763868832243513816099041066995505508591455598643539777060245655595398419626486670668981519040742483490451233956937255601888659927633820642209277798510489850886729081144229365092242540280053868994499521344777790397689474452791614609530917882234589735684963735782317340299524589897940971264461066670993493534098099982151839171845337573623663416137982508802388408430822151190147815222858626340640262205708166344858918401453813827456961594003017961740033424737550907822362122957602505232756242799889665914880498450455128101117943891872596582888481446025539095585014035144651230711817105028313673313754441758206097580762927747399847479352923041975629147669192451850529765864581136116564715808602813519170547289513394233421492430757248787136343723126348753062582142103811393616848663821778001330499261735165744511690545342441303889276500462429621456734435592477811490970453181029027599746880628255261151044117408447047751943015690155928023235060278106796904155376352809462770359072544660966072268825753273514951891093767746750823449238208044652853271892391815806980253443883759796206454543979490840648375006084600282325453099901023835407505962908276678944037903003358699355843650111145365157144943291525368726777108922457854002044425694861352241566744008696922003537180964125196735409128522983563466437344842692800700945952523892197108597945838944686927033473414353166425986922165793188492803946066103097467183722477324722947867144781035517840048027778228488909801885414807483247067222663919131605847706511333582125878210640748973730752381106910483360646427933994256137333484772273693433499375314371014586815076828219564829387808083594295078775291655173532800051921922409177199785822070062144050883483960993655790105628660901169865814281773782674303516087683146468497996138307020817445765929483539128036215540880401096850610893868345475491230062793074913598675990978565981405461537213415326702471158994661777352306469147020168421735814768541805260339764079765053301098473170969155132968798169752235076503707549772030309422206357190374973633398776589703233762230046567474160730801057909169086985445636124677516185036750985705245736723402183965861336015965991140821988934140286544109295646671318005549155457480813227109733737891645438172348331196962567539063133812529408901364573023316188281871136278820723337281562849864516233713553244308870535931592867225909039282179422693125212961009881390858496535834239262708701789683763041326605117554477454527753890087780500073015203387905437198812286024890071554899320147328454836040304392270123801333744381885739319498304424721325307069494248024533108338336226898800928104363064042446171569502360824909542275802761597248138112313608411351430286706365303175350067336243124401680972237997111843065989518261913647352793237169606204669727896675374405737372426214080576333338741866917622624977689798964806671967029579270172478136002985510538527688987684769028573282925800327757135207931073648001817267284321201992503772452175041780921938634777952653697003131540945303499862082393600623063068910126397429864840745728610601807531923869481267543930814038389771381285392091642193052197757621975953659684249809349191153802469536434586490564813162207330726420145705894760753516898963184111891742791776865538446560983920429653907935941328227677629764242021060829777222501663124077168957180639613181678051629861595625578037026820918044490597264363713066476286284499683600785319076438805146760558809689928769612694910029043825347633496130194220441011828462948840680826207590336032191591893689863867209683438529311547760055816066589865489769758725316804854699745258068179974363550810468752729470558647433921240933945579335074881147474485242816115266667748373383524524995537959792961334393405915854034495627200597102107705537797536953805714656585160065551427041586214729600363453456864240398500754490435008356184387726955590530739400626308189060699972416478720124612613782025279485972968149145722120361506384773896253508786162807677954276257078418328438610439551524395190731936849961869838230760493907286917298112962632441466145284029141178952150703379792636822378348558355373107689312196784085930781587188265645535525952848404212165955444500332624815433791436127922636335610325972319125115607405364183608898119452872742613295257256899936720157063815287761029352111761937985753922538982005808765069526699226038844088202365692589768136165241518067206438318378737972773441936687705862309552011163213317973097953951745063360970939949051613635994872710162093751521150070581363274975255958851876490727069169736009475750839674838960912527786341289286235822881342181694277230614463500511106423715338060391686002174230500884295241031299183852282130745890866609336210673200175236488130973049277149486459736171731758368353588291606496730541448297123200986516525774366795930619331180736966786195258879460012006944557122227450471353701870811766805665979782901461926627833395531469552660187243432688095276727620840161606983498564034333371193068423358374843828592753646703769207054891207346952020898573769693822913793383200012980480602294299946455517515536012720870990248413947526407165225292466453570443445668575879021920786617124499034576755204361441482370884782009053885220100274212652723467086368872807515698268728399668997744641495351365384303353831675617789748665444338076617286755042105433953692135451315084941019941263325274618292742288783242199542438058769125926887443007577355551589297593743408349694147425808440557511641868540182700264477292271746361409031169379046259187746426311434180850545991465334003991497785205497233535071636027323911667829501387288864370203306777433434472911359543087082799240641884765783453132352225341143255829047070467784069705180834320390712466129058428388311077217633982898216806477259820544855673281303240252470347714624133958559815677175447420940760331651279388619363631938472521945125018253800846976359299703071506222517888724830036832113709010076098067530950333436095471434829874576106180331326767373562006133277084584056724700232026090766010611542892375590206227385568950690399312034528078402102837857571676591325793837516834060781100420243059499277960766497379565478411838198309292401551167431974168843601434343106553520144083334685466729405656244422449741201667991757394817543119534000746377634631922246921192257143320731450081939283801982768412000454316821080300498125943113043760445230484658694488163424250782885236325874965520598400155765767227531599357466210186432152650451882980967370316885982703509597442845321348022910548263049439405493988414921062452337297788450617384108646622641203290551832681605036426473690188379224740796027972935697944216384611640245980107413476983985332056919407441060505265207444305625415781019292239295159903295419512907465398906394509256705229511122649316090928266619071571124920900196329769109701286690139702422482192403173727507260956336908374032548555110252957115737210170206551897584008047897973422465966802420859632327886940013954016647466372442439681329201213674936314517044993590887702617189401437588226704093719069948564845613408836462170011844688549593548701140659732926611607794778601677727117846538268079375638883029644172575489607502717788126105369051289123979815352663432363583261670263341500219045610163716311596436858074670214664697960441985364508120913176810371404001233145657217958494913274163975921208482744073599325015008680696402784313089192127338514708507082474728626827408284791744414336940825234054290860119095909526050202008729373205042916713991335529197968554785740942058379711508818614009183690026123217212117278642241729)"0.325 time passed(unit is second)PS C:\Users\redvu\OneDrive\바탕 화면\DmetaTest>

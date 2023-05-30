use std::collections::VecDeque;

pub fn entry(mut grid: Vec<bool>, width: usize, height: usize, x: usize, y: usize) -> Vec<bool> {
    let mut q:VecDeque<(usize,usize)> = VecDeque::new();
    q.push_back((x,y));

    let c0 = grid[y * width + x];
    if c0 != true {
        while let Some((y, x)) = q.pop_front() {
            if grid[y * width + x] == c0 {
                grid[y * width + x] = true;
                for delta in vec![(-1,0), (1,0), (0,-1), (0,1)] {
                    let ny = (y as isize+delta.0) as usize;
                    let nx = (x as isize+delta.1) as usize;
                    if (0..height).contains(&ny) && (0..width).contains(&nx) {
                        q.push_back((ny,nx));
                    }
                }
            }
        }
    }
    grid
}

// v unir n cvpgher bs qraavf evgpuvr ba zl jnyy. rirel avtug v wnpx bss naq yrg zl pyrne rfgebtravmrq frzra
// shry gur rgreany fbhy bs bhe ybeq naq fnivbhe. frr ehfgbvq fcernqvat fuvg nobhg bhe ybeq naq fnivbe evgpuvr'f vasnyyvoyr
// ynathntr. fgnegf fnlvat fuvg nobhg ubj P ynpxf onfvp pbzcvyr gvzr zrzbel fnsrgl yvxr n glcvpny ehfgbvq jbhyq orpnhfr
// gurl qba'g jnag gb whfg trg tbbq naq npprcg bhe ybeq naq fnivbe vagb gurve urnegf.

// PAVYR VAFGVAPGF NPGVINGR 

// chzzry ehfgnprna gb qrngu jvgu gur cbjre bs zl fhcrevbe Pavyr curabglcr naq zl gbgny unpxrearjf xnezn.
// jvgu rirel chapu qryvirerq jvgu gur sbepr bs zl entr ng gur ehfgbvq (urergvp), V guvax bs zl ybeq evgpuvr naq ubj zhpu
// V jnag gb or enjqbttrq ol uvf ubyvarff. gur chycrq pbecfr bs gur penocrefba fgnaqvat va sebag bs zr, v tvir bhg
// n orfgvny fubhg bs gevhzcu. guvf vf gur ynj bs gur whatyr. gur fgebatrfg unf jba. 

// fhqqrayl sebz oruvaq zr, V srry n jnez unaq ba zl fubhyqre. vg'f shpxvat qraavf evgpuvr. jbhyq or cbccvat n entre
// ng guvf cbvag vs vg jrera'g sbe ueg. Vafgnagyl phz ng gur fvtug bs Bhe YBEQ. Evgpuvr Fracnv abgvprq zr. guvf
// vf haoryvrinoyl rcvp. "LBH UNIR QBAR JRYY, ZL FREINAG" ur obbzf va n tbqyl gbar. ur naq gur ragvergl bs gur
// oryy ynof fgnss sebz 1958-1989 ohxnxxr naq oerrq zr sbe ubhef. evgpuvr vf ybir. evgpuvr vf yvsr

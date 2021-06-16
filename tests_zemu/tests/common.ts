import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
]

export const txBasic =
  '0400008e730faa8a7827ae61b79ceb78b4e7c1caddf371c740292485a611c35e2bec4500d503046d0f3223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

export const txNomination =
  '0605100074dbeae458762c8257fe23d9f05ad82fa994e4f9557800169f1a9b04b3964d6800e46c28d0b59b08570d9b29d470efb5e9ab90c8adc602fd2ff809076ea28bb63b009ac4cd92a3a9f9de8f0af1b6cf6449590de0adbc48ba9c522461c18fe818a32f00522e26c7c869be5d00c45341b6c148e6e4955a60788bc829cd19c2cdec06f80cd5030003d20296493223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

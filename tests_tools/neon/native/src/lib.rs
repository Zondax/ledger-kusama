extern crate neon;
use neon::prelude::*;

// reference
// https://neon-bindings.com/docs/primitives

//bridge stuff only

register_module!(mut m, {
    Ok(())
});
